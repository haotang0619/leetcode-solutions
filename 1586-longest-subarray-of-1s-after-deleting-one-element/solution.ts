function longestSubarray(nums: number[]): number {
  let start = -1;
  let prev = -1;
  let answer = 0;
  nums.push(0);
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === 0) {
      answer = Math.max(answer, i - start - 2);
      start = prev;
      prev = i;
    }
  }
  return answer;
}
