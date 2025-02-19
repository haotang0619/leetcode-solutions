function majorityElement(nums: number[]): number {
  let ans = nums[0];
  let cnt = 0;
  for (let i = 0; i < nums.length; i++) {
    if (cnt === 0) ans = nums[i];
    if (nums[i] === ans) cnt++;
    else cnt--;
  }
  return ans;
}
