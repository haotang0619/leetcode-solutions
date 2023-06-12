function longestOnes(nums: number[], k: number): number {
  const zeros = nums.reduce(
    (z, num, i) => (num === 0 ? [...z, i] : z),
    [] as number[],
  );
  if (zeros.length === 0) return nums.length;

  let start = -1;
  let answer = 0;
  for (let i = 0; i < zeros.length; i++) {
    start = zeros[i - k] ?? -1;
    const end = zeros[i + 1] ?? nums.length;
    answer = Math.max(answer, end - start - 1);
  }
  return answer;
}
