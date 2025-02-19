function maxProfit(prices: number[], fee: number): number {
  const n = prices.length;
  const dp = [[-prices[0], 0], []];
  for (let i = 1; i < n; i++) {
    const idx = i % 2;
    dp[idx][0] = Math.max(dp[1 - idx][0], dp[1 - idx][1] - prices[i]);
    dp[idx][1] = Math.max(dp[1 - idx][1], dp[1 - idx][0] + prices[i] - fee);
  }
  return Math.max(...dp[(n - 1) % 2]);
}
