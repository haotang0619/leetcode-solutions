function maxOperations(nums: number[], k: number): number {
  nums.sort((a, b) => a - b);
  let p1 = 0;
  let p2 = nums.length - 1;
  let answer = 0;
  while (p1 < p2) {
    const sum = nums[p1] + nums[p2];
    if (sum === k) answer++, p1++, p2--;
    else if (sum < k) p1++;
    else p2--;
  }
  return answer;
}
