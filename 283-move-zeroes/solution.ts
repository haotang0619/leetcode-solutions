/**
 Do not return anything, modify nums in-place instead.
 */
function moveZeroes(nums: number[]): void {
  let i = 0;
  let j = 1;
  while (true) {
    while (nums[i] !== 0 && i < nums.length) i++;
    if (i >= nums.length) break;
    j = Math.max(j, i + 1);
    while (nums[j] === 0) j++;
    if (j >= nums.length) break;
    [nums[i], nums[j]] = [nums[j], nums[i]];
  }
}
