function recursion(
  answer: number[][],
  nums: number[],
  now: number[],
  size: number,
) {
  if (now.length === size) {
    answer.push(now);
    return;
  }
  nums.forEach((n) => {
    if (n > (now.slice(-1)[0] ?? -11))
      recursion(answer, nums, [...now, n], size);
  });
}

function subsets(nums: number[]): number[][] {
  const answer = [];
  nums.sort((a, b) => a - b);
  for (let i = 0; i <= nums.length; i++) recursion(answer, nums, [], i);
  return answer;
}
