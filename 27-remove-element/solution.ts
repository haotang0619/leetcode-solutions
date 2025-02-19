function removeElement(nums: number[], val: number): number {
  let k = nums.length;
  for (let i = 0; i < k; i++) {
    while (nums[i] === val && i < k) {
      [nums[i], nums[k - 1]] = [nums[k - 1], nums[i]];
      k--;
    }
  }
  return k;
}
