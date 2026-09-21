# LeetCode Solutions

My LeetCode solutions, auto-synced from LeetCode to this repo via a scheduled
GitHub Action. Each Accepted submission ends up in its own folder with the
problem statement and my solution code.

## Structure

```
<problem-id>-<problem-slug>/
  README.md       # problem statement (fetched from LeetCode)
  solution.<ext>   # my accepted solution, extension depends on language
```

## How syncing works

- `scripts/sync-leetcode.js` calls LeetCode's GraphQL API to find any newly
  Accepted submissions since the last sync, then writes them to this repo in
  a single commit.
- `.github/workflows/sync-leetcode.yml` runs that script:
  - automatically every day at 00:00 UTC, and
  - on demand via the **Run workflow** button under the *Actions* tab
    (useful the first time, to backfill all historical Accepted submissions).

## Setup (for my own reference)

1. Repo secrets (*Settings > Secrets and variables > Actions*):
   - `LEETCODE_CSRF_TOKEN`
   - `LEETCODE_SESSION`

   Both come from the browser cookies after logging into leetcode.com
   (DevTools > Network > any request to leetcode.com > Request Headers >
   `cookie:`).

2. *Settings > Actions > General > Workflow permissions* → **Read and write
   permissions** (needed so the workflow can push commits).

3. First run: *Actions* tab → **Sync LeetCode** → **Run workflow**. This
   backfills every historical Accepted submission (one single commit).

4. After that, the daily cron keeps it up to date automatically. Re-solving
   an already-synced problem with a new Accepted submission will update its
   folder on the next sync.

## Credit

The submission-fetching and watermark logic (deciding which submissions are
"new" since the last sync) is adapted from
[joshcai/leetcode-sync](https://github.com/joshcai/leetcode-sync) by Josh Cai
and contributors. This repo's version rewrites the commit step to batch every
file from one sync run into a single commit instead of one commit per
submission. Please check that project's license before reusing its code
beyond personal use.
