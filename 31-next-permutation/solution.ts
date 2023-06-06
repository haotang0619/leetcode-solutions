/**
 Do not return anything, modify nums in-place instead.
 */
function nextPermutation(nums: number[]): void {
  const max = nums.length;
  let pos = 0;

  for (let i = max - 1; i >= 0; i--) {
    for (let j = max; j >= i; j--) {
      if (nums[i] < nums[j]) {
        pos = i + 1;
        const tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        break;
      }
    }
    if (pos !== 0) break;
  }

  for (let i = pos; i < max - 1; i++) {
    for (let j = i + 1; j < max; j++) {
      if (nums[i] > nums[j]) {
        const tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;
      }
    }
  }
}
