function countDistinct(nums: number[], k: number, p: number): number {
  const n = nums.length;
  const prefixSum = [];

  for (let i = 0; i < n; i++) {
    if (nums[i] % p === 0) prefixSum[i] = (prefixSum[i - 1] ?? 0) + 1;
    else prefixSum[i] = prefixSum[i - 1] ?? 0;
  }

  let answer = 0;
  let seen = new Set();
  for (let i = 1; i <= n; i++) {
    for (let j = 0; j <= n - i; j++) {
      const subArr = JSON.stringify(nums.slice(j, j + i));
      const cnt = prefixSum[j + i - 1] - (prefixSum[j - 1] ?? 0);
      if (cnt <= k && !seen.has(subArr)) {
        answer += 1;
        seen.add(subArr);
      }
    }
  }
  return answer;
}
