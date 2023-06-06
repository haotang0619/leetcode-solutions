function matrixSum(nums: number[][]): number {
  nums.forEach((n) => n.sort((a, b) => b - a));
  const m = nums[0].length;
  const newNums = [...Array(m).keys()].map((i) => nums.map((n) => n[i]));
  newNums.forEach((n) => n.sort((a, b) => b - a));
  return newNums.reduce((acc, cur) => acc + cur[0], 0);
}
