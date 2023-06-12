function rob(nums: number[]): number {
  const dp = nums.map(() => 0);
  for (let i = 0; i < nums.length; i++) {
    dp[i] = Math.max(dp[i - 1] ?? 0, (dp[i - 2] ?? 0) + nums[i]);
  }
  return dp[nums.length - 1];
}
