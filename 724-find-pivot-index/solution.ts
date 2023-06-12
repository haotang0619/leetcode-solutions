function pivotIndex(nums: number[]): number {
  const prefixSum = nums.reduce(
    (acc, num, i) => [...acc, (acc[i - 1] ?? 0) + num],
    [] as number[],
  );
  const suffixSum = nums
    .reverse()
    .reduce((acc, num, i) => [...acc, (acc[i - 1] ?? 0) + num], [] as number[])
    .reverse();

  for (let i = 0; i < nums.length; i++) {
    if (prefixSum[i] === suffixSum[i]) return i;
  }
  return -1;
}
