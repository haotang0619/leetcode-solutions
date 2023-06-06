function findDisappearedNumbers(nums: number[]): number[] {
  const n = nums.length;
  const result = {};
  for (let i = 1; i <= n; i++) result[i] = 1;
  for (let i = 0; i < n; i++) delete result[nums[i]];
  return Object.keys(result).map((i) => parseInt(i));
}
