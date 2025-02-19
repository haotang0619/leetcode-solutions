function removeDuplicates(nums: number[]): number {
  const seen = new Set();
  let k = 0;
  for (let i = 0; i < nums.length; i++) {
    if (!seen.has(nums[i])) nums[k++] = nums[i];
    seen.add(nums[i]);
  }
  return k;
}
