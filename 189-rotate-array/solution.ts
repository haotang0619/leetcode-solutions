/**
 Do not return anything, modify nums in-place instead.
 */
function rotate(nums: number[], k: number): void {
  const len = nums.length;
  let n = len;
  for (let i = 0; i < len; i++) {
    if (n === 0) break;
    let to = (i + k) % len;
    let temp1 = nums[i];
    let temp2 = nums[to];
    while (n > 0) {
      n--;
      nums[to] = temp1;
      if (to === i) break;
      temp1 = temp2;
      to = (to + k) % len;
      temp2 = nums[to];
    }
  }
}
