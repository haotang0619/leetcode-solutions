function positiveMod(a: number, n: number): number {
  const m = a % n;
  return m < 0 ? m + n : m;
}

// https://leetcode.com/problems/make-array-empty/solutions/3466731/just-sort-without-any-other-tricky-data-structures:
function countOperationsToEmptyArray(nums: number[]): number {
  const len = nums.length;
  const indexes = [...Array(len).keys()];
  indexes.sort((a, b) => nums[a] - nums[b]);

  let answer = 0;
  let n = 0;
  for (let i = 1; i < len; i++) {
    if (indexes[i] < indexes[i - 1]) n++;
    answer += n;
  }

  return answer + len;
}
