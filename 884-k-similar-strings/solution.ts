// https://leetcode.com/problems/k-similar-strings/discuss/2385252/Python-BFS-Solution-(fully-explained-and-commented):
function kSimilarity(s1: string, s2: string): number {
  const deque = [s1];
  const seen = new Set<string>();
  let ans = 0;

  let idx = 0;
  while (!!deque[idx]) {
    const len = deque.length;
    for (let _ = idx; _ < len; _++) {
      const s = deque[idx++];
      if (s === s2) return ans;

      let i = 0;
      while (s[i] === s2[i]) i++;
      for (let j = i + 1; j < s.length; j++) {
        if (s[i] !== s1[j] && s[i] === s2[j]) {
          const s3 =
            s.slice(0, i) + s[j] + s.slice(i + 1, j) + s[i] + s.slice(j + 1);

          if (!seen.has(s3)) {
            seen.add(s3);
            deque.push(s3);
          }
        }
      }
    }
    ans++;
  }

  return 0;
}
