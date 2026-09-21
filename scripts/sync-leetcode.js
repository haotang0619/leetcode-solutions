/**
 * sync-leetcode.js
 *
 * Fetches newly Accepted LeetCode submissions since the last sync and
 * commits them to this repo as a SINGLE git commit per run.
 *
 * Core submission-fetching / watermark logic is adapted from
 * joshcai/leetcode-sync (https://github.com/joshcai/leetcode-sync), MIT-style
 * open source GitHub Action. Credit: Josh Cai (joshcai) and contributors.
 * This version rewrites the commit step to batch all changed files from a
 * single sync run into one commit instead of one commit per submission.
 */

const axios = require("axios");
const { Octokit } = require("@octokit/rest");
const path = require("path");

const BASE_URL = "https://leetcode.com";

const LANG_TO_EXTENSION = {
  bash: "sh",
  c: "c",
  cpp: "cpp",
  csharp: "cs",
  dart: "dart",
  elixir: "ex",
  erlang: "erl",
  golang: "go",
  java: "java",
  javascript: "js",
  kotlin: "kt",
  mssql: "sql",
  mysql: "sql",
  oraclesql: "sql",
  php: "php",
  python: "py",
  python3: "py",
  pythondata: "py",
  postgresql: "sql",
  racket: "rkt",
  ruby: "rb",
  rust: "rs",
  scala: "scala",
  swift: "swift",
  typescript: "ts",
};

// ---- config (from env vars set in the workflow) ----
const GITHUB_TOKEN = process.env.GITHUB_TOKEN;
const [OWNER, REPO] = (process.env.GITHUB_REPOSITORY || "").split("/");
const LEETCODE_CSRF_TOKEN = process.env.LEETCODE_CSRF_TOKEN;
const LEETCODE_SESSION = process.env.LEETCODE_SESSION;
const FILTER_DUPLICATE_SECS = Number(process.env.FILTER_DUPLICATE_SECS || 86400);
const DESTINATION_FOLDER = process.env.DESTINATION_FOLDER || "";
// Optional static override. When unset, the header is derived from what was
// actually synced (see buildCommitHeader) instead of being a constant string.
const COMMIT_HEADER = process.env.COMMIT_HEADER || "";
// Machine-readable marker used to find the last sync commit (the watermark).
// Kept independent of the header text so the header is free to vary per run.
const SYNC_MARKER = "Sync-Source: leetcode-sync";

function log(message) {
  console.log(`[${new Date().toUTCString()}] ${message}`);
}

const delay = (ms) => new Promise((res) => setTimeout(res, ms));

function pad(n) {
  const s = "000" + n;
  return s.length > 4 ? n : s.substring(s.length - 4);
}

function normalizeName(problemName) {
  return problemName
    .toLowerCase()
    .replace(/\s/g, "-")
    .replace(/[^a-zA-Z0-9_-]/gi, "");
}

function graphqlHeaders() {
  return {
    "content-type": "application/json",
    origin: BASE_URL,
    referer: BASE_URL,
    cookie: `csrftoken=${LEETCODE_CSRF_TOKEN}; LEETCODE_SESSION=${LEETCODE_SESSION};`,
    "x-csrftoken": LEETCODE_CSRF_TOKEN,
  };
}

async function getInfo(submission, maxRetries = 5, retryCount = 0) {
  const data = JSON.stringify({
    query: `query submissionDetails($submissionId: Int!) {
      submissionDetails(submissionId: $submissionId) {
        runtimePercentile
        memoryPercentile
        code
        question { questionId }
      }
    }`,
    variables: { submissionId: submission.id },
  });

  try {
    const response = await axios.post(`${BASE_URL}/graphql/`, data, {
      headers: graphqlHeaders(),
    });
    const d = response.data?.data?.submissionDetails;
    const runtimePerc =
      d.runtimePercentile !== null && d.runtimePercentile !== undefined
        ? `${d.runtimePercentile.toFixed(2)}%`
        : "N/A";
    const memoryPerc =
      d.memoryPercentile !== null && d.memoryPercentile !== undefined
        ? `${d.memoryPercentile.toFixed(2)}%`
        : "N/A";
    const qid = d?.question?.questionId ? pad(d.question.questionId.toString()) : "N/A";

    log(`Got info for submission #${submission.id}`);
    return { ...submission, runtimePerc, memoryPerc, qid, code: d.code };
  } catch (exception) {
    if (retryCount >= maxRetries) {
      if (exception.response && exception.response.status === 403) {
        log(`Skipping locked problem: ${submission.title}`);
        return null;
      }
      throw exception;
    }
    log(`Error fetching submission info, retrying in ${3 ** retryCount}s...`);
    await delay(3 ** retryCount * 1000);
    return getInfo(submission, maxRetries, retryCount + 1);
  }
}

async function getQuestionData(titleSlug) {
  log(`Getting question data for ${titleSlug}...`);
  const graphql = JSON.stringify({
    query: `query getQuestionDetail($titleSlug: String!) {
      question(titleSlug: $titleSlug) { content }
    }`,
    variables: { titleSlug },
  });

  try {
    const response = await axios.post(`${BASE_URL}/graphql/`, graphql, {
      headers: graphqlHeaders(),
    });
    return response.data.data.question.content;
  } catch (error) {
    if (error.response && error.response.status === 403) {
      log(`Skipping locked problem: ${titleSlug}`);
      return null;
    }
    throw error;
  }
}

// Returns false once we've reached submissions already synced in a previous run.
function addToSubmissions({ response, lastTimestamp, submissions_dict, submissions }) {
  for (const submission of response.data.data.submissionList.submissions) {
    const ts = Number(submission.timestamp);
    if (ts <= lastTimestamp) return false;
    if (submission.statusDisplay !== "Accepted") continue;

    const name = normalizeName(submission.title);
    const lang = submission.lang;
    if (!submissions_dict[name]) submissions_dict[name] = {};

    // Only one submission per problem+language within FILTER_DUPLICATE_SECS.
    if (
      submissions_dict[name][lang] &&
      submissions_dict[name][lang] - ts < FILTER_DUPLICATE_SECS
    ) {
      continue;
    }
    submissions_dict[name][lang] = ts;
    submissions.push(submission);
  }
  return true;
}

// Builds the two tree entries (README.md + solution file) for one submission.
function buildTreeEntries(submission, questionData) {
  const name = normalizeName(submission.title);
  if (!LANG_TO_EXTENSION[submission.lang]) {
    throw new Error(`Language ${submission.lang} has no registered extension.`);
  }
  const qid = submission.qid && submission.qid !== "N/A" ? `${submission.qid}-` : "";
  const folderName = `${qid}${name}`;
  const questionPath = path.join(DESTINATION_FOLDER, folderName, "README.md");
  const solutionPath = path.join(
    DESTINATION_FOLDER,
    folderName,
    `solution.${LANG_TO_EXTENSION[submission.lang]}`
  );

  const summaryLine = `- ${submission.qid !== "N/A" ? submission.qid + " " : ""}${submission.title} (${submission.lang}) - Runtime ${submission.runtime} (${submission.runtimePerc}), Memory ${submission.memory} (${submission.memoryPerc})`;

  const submittedAt = new Date(Number(submission.timestamp) * 1000).toISOString();
  const readmeContent = `> Submitted: ${submittedAt}\n\n${questionData ?? "Unable to fetch the problem statement."}`;

  return {
    treeEntries: [
      {
        path: path.normalize(questionPath),
        mode: "100644",
        content: readmeContent,
      },
      {
        path: path.normalize(solutionPath),
        mode: "100644",
        content: `${submission.code}\n`,
      },
    ],
    summaryLine,
  };
}

// Derives a commit header from what was actually synced, so it's not the
// same string every run: a single problem gets its own name in the header,
// a batch gets a count + sample of question numbers.
function buildCommitHeader(metas) {
  if (metas.length === 1) {
    const { qid, title, lang } = metas[0];
    return `solve: ${qid !== "N/A" ? qid + " " : ""}${title} (${lang})`;
  }
  const qids = metas.map((m) => m.qid).filter((qid) => qid !== "N/A");
  if (qids.length === 0) return `chore: sync ${metas.length} LeetCode solutions`;
  const shown = qids.slice(0, 5).map((qid) => `#${qid}`).join(", ");
  const rest = qids.length > 5 ? `, +${qids.length - 5} more` : "";
  return `chore: sync ${metas.length} LeetCode solutions (${shown}${rest})`;
}

async function sync() {
  if (!GITHUB_TOKEN || !OWNER || !REPO || !LEETCODE_CSRF_TOKEN || !LEETCODE_SESSION) {
    throw new Error(
      "Missing one of GITHUB_TOKEN / GITHUB_REPOSITORY / LEETCODE_CSRF_TOKEN / LEETCODE_SESSION."
    );
  }

  const octokit = new Octokit({
    auth: GITHUB_TOKEN,
    userAgent: "leetcode-sync (single-commit fork)",
  });

  // 1. Find the watermark: the timestamp of the last submission we synced.
  const commits = await octokit.repos.listCommits({ owner: OWNER, repo: REPO, per_page: 100 });
  if (commits.data.length === 0) {
    throw new Error(
      "Repo has no commits yet. Create the repo with an initial commit (e.g. a README) before running this."
    );
  }

  let lastTimestamp = 0;
  let commitInfo = commits.data[commits.data.length - 1].commit.author;
  for (const c of commits.data) {
    if (!c.commit.message.includes(SYNC_MARKER)) continue;
    commitInfo = c.commit.author;
    lastTimestamp = Date.parse(c.commit.committer.date) / 1000;
    break;
  }
  log(`Watermark (last synced timestamp): ${lastTimestamp}`);

  // 2. Page through LeetCode submissions until we hit the watermark.
  let response = null;
  let offset = 0;
  const submissions = [];
  const submissions_dict = {};
  do {
    log(`Fetching submissions, offset ${offset}`);
    const fetchPage = async (maxRetries, retryCount = 0) => {
      try {
        const graphql = JSON.stringify({
          query: `query ($offset: Int!, $limit: Int!, $slug: String) {
            submissionList(offset: $offset, limit: $limit, questionSlug: $slug) {
              hasNext
              submissions { id lang timestamp statusDisplay runtime title memory titleSlug }
            }
          }`,
          variables: { offset, limit: 20, slug: undefined },
        });
        const resp = await axios.post(`${BASE_URL}/graphql/`, graphql, {
          headers: graphqlHeaders(),
        });
        return resp;
      } catch (exception) {
        if (retryCount >= maxRetries) throw exception;
        log(`Error fetching submissions, retrying in ${3 ** retryCount}s...`);
        await delay(3 ** retryCount * 1000);
        return fetchPage(maxRetries, retryCount + 1);
      }
    };
    const maxRetries = response === null ? 0 : 5;
    if (response !== null) await delay(1000);
    response = await fetchPage(maxRetries);

    if (!addToSubmissions({ response, lastTimestamp, submissions_dict, submissions })) break;
    offset += 20;
  } while (response.data.data.submissionList.hasNext);

  if (submissions.length === 0) {
    log("No new Accepted submissions since last sync. Nothing to do.");
    return;
  }

  // 3. Fetch code + question content, build one big tree (oldest submission first).
  const allTreeEntries = [];
  const summaryLines = [];
  const metas = [];
  let maxTimestamp = lastTimestamp;

  for (let i = submissions.length - 1; i >= 0; i--) {
    const full = await getInfo(submissions[i]);
    if (full === null) continue; // locked problem, skip

    const questionData = await getQuestionData(full.titleSlug);
    if (questionData === null) continue; // locked problem, skip

    const { treeEntries, summaryLine } = buildTreeEntries(full, questionData);
    allTreeEntries.push(...treeEntries);
    summaryLines.push(summaryLine);
    metas.push({ qid: full.qid, title: full.title, lang: full.lang });
    maxTimestamp = Math.max(maxTimestamp, Number(full.timestamp));
  }

  if (allTreeEntries.length === 0) {
    log("All new submissions were locked/unavailable. Nothing to commit.");
    return;
  }

  // 4. One tree, one commit, one ref update.
  const repoInfo = await octokit.repos.get({ owner: OWNER, repo: REPO });
  const defaultBranch = repoInfo.data.default_branch;
  const baseTreeSHA = commits.data[0].commit.tree.sha;
  const parentCommitSHA = commits.data[0].sha;

  log(`Creating single commit for ${summaryLines.length} problem(s)...`);
  const treeResponse = await octokit.git.createTree({
    owner: OWNER,
    repo: REPO,
    base_tree: baseTreeSHA,
    tree: allTreeEntries,
  });

  const header = COMMIT_HEADER || buildCommitHeader(metas);
  const message = `${header}\n\n${summaryLines.join("\n")}\n\n${SYNC_MARKER}`;
  const date = new Date(maxTimestamp * 1000).toISOString();

  const commitResponse = await octokit.git.createCommit({
    owner: OWNER,
    repo: REPO,
    message,
    tree: treeResponse.data.sha,
    parents: [parentCommitSHA],
    author: { name: commitInfo.name, email: commitInfo.email, date },
    committer: { name: commitInfo.name, email: commitInfo.email, date },
  });

  await octokit.git.updateRef({
    owner: OWNER,
    repo: REPO,
    ref: `heads/${defaultBranch}`,
    sha: commitResponse.data.sha,
    force: true,
  });

  log(`Done. Committed ${summaryLines.length} problem(s) in a single commit.`);
}

sync().catch((err) => {
  log(err.stack || String(err));
  process.exit(1);
});
