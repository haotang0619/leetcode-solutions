function twoSum(nums: number[], target: number): number[] {
  const n = nums.length;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (i !== j && nums[i] + nums[j] === target) return [i, j];
    }
  }
  return [n - 1, n - 1];
}
