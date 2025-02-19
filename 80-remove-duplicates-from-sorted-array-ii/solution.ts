function removeDuplicates(nums: number[]): number {
  let k = 1;
  let prev = [nums[0], 1];
  for (let i = 1; i < nums.length; i++) {
    if (nums[i] === prev[0]) {
      if (prev[1] === 1) {
        prev[1] = 2;
        nums[k++] = nums[i];
      }
    } else {
      prev = [nums[i], 1];
      nums[k++] = nums[i];
    }
  }
  return k;
}
