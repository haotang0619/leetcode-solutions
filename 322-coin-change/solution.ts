function coinChange(coins: number[], amount: number): number {
  const INF = 1e9 + 7;
  const dp: number[] = [0];
  for (let i = 1; i <= amount; i++) {
    dp[i] = INF;
    for (let j = 0; j < coins.length; j++) {
      if (dp[i - coins[j]] >= 0 && dp[i - coins[j]] !== INF) {
        dp[i] = Math.min(dp[i - coins[j]] + 1, dp[i]);
      }
    }
  }
  return dp[amount] === INF ? -1 : dp[amount];
}
