const INF = 1e9 + 7;
function minDistance(word1: string, word2: string): number {
  const m = word1.length;
  const n = word2.length;
  const dp = Array.from({ length: m + 1 }).map(() => [] as number[]);
  for (let i = 0; i <= m; i++) {
    for (let j = 0; j <= n; j++) {
      if (word1[i - 1] === word2[j - 1]) {
        dp[i][j] = dp[i - 1]?.[j - 1] ?? 0;
      } else {
        dp[i][j] =
          1 +
          Math.min(
            dp[i - 1]?.[j - 1] ?? INF,
            dp[i - 1]?.[j] ?? INF,
            dp[i][j - 1] ?? INF,
          );
      }
    }
  }
  return dp[m][n];
}
