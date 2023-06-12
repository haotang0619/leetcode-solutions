const MOD = 1e9 + 7;
function numTilings(n: number): number {
  const dp = Array.from({ length: n }).map(() => [0, 0, 0]);
  dp[0] = [1, 0, 0];
  dp[1] = [2, 1, 1];
  for (let i = 2; i < n; i++) {
    dp[i][0] =
      (dp[i - 2][0] + dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
    dp[i][1] = (dp[i - 2][0] + dp[i - 1][2]) % MOD;
    dp[i][2] = (dp[i - 2][0] + dp[i - 1][1]) % MOD;
  }
  return dp[n - 1][0];
}
