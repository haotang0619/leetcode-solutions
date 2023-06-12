function productExceptSelf(nums: number[]): number[] {
  const answer: number[] = [];
  let init = 1;
  for (let i = 0; i < nums.length; i++) {
    answer[i] = init;
    init *= nums[i];
  }

  init = 1;
  for (let i = nums.length - 1; i >= 0; i--) {
    answer[i] = answer[i] * init;
    init *= nums[i];
  }
  return answer;
}
