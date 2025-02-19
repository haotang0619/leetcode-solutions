function minSubArrayLen(target: number, nums: number[]): number {
  let p1 = 0;
  let sum = 0;
  let answer = 1e9 + 7;
  for (let p2 = 0; p2 < nums.length; p2++) {
    sum += nums[p2];
    while (sum >= target) {
      if (sum - nums[p1] >= target) {
        sum -= nums[p1];
        p1++;
      } else {
        answer = answer < p2 - p1 + 1 ? answer : p2 - p1 + 1;
        break;
      }
    }
  }
  return answer === 1e9 + 7 ? 0 : answer;
}
