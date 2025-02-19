function canJump(nums: number[]): boolean {
  let maxIdx = 0;
  for (let i = 0; i <= maxIdx; i++) {
    maxIdx = maxIdx > i + nums[i] ? maxIdx : i + nums[i];
    if (maxIdx >= nums.length - 1) break;
  }
  return maxIdx >= nums.length - 1;
}
