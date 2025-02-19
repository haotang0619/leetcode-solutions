// https://leetcode.com/problems/single-number-ii/solutions/3621277/simple-solution-with-o-1-space-o-n-time-complexity:
function singleNumber(nums: number[]): number {
  let answer = 0;
  for (let i = 0; i < 32; i++) {
    let ones = 0;
    let zeroes = 0;
    for (let n of nums) (n >> i) & 1 ? ones++ : zeroes++;
    if (ones % 3) answer |= 1 << i;
  }
  return answer;
}
