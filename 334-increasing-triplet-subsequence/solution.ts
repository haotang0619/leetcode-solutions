// https://leetcode.com/problems/increasing-triplet-subsequence/solutions/3549612/python-easy-solution/?envType=study-plan-v2&envId=leetcode-75:
function increasingTriplet(nums: number[]): boolean {
  let n1 = 2 ** 31;
  let n2 = 2 ** 31;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] <= n1) n1 = nums[i];
    else if (nums[i] <= n2) n2 = nums[i];
    else return true;
  }
  return false;
}
