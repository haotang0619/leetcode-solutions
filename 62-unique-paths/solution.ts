function uniquePaths(m: number, n: number): number {
  const dp = Array.from({ length: m }).map(() => [] as number[]);
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      dp[i][j] = (dp[i - 1]?.[j] || 0) + (dp[i][j - 1] || 0) || 1;
    }
  }
  return dp[m - 1][n - 1];
}
