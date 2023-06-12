function findMaxAverage(nums: number[], k: number): number {
  let answer = -1e9 - 7;
  let now = 0;
  for (let i = 0; i < nums.length; i++) {
    now += nums[i] - (nums[i - k] ?? 0);
    if (i >= k - 1) answer = Math.max(answer, now / k);
  }
  return answer;
}
