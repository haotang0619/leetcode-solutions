function jump(nums: number[]): number {
  if (nums.length === 1) return 0;
  let answer = 0;
  let now = 0;
  while (true) {
    answer++;
    const step = nums[now];
    if (now + step >= nums.length - 1) break;
    let nextNow = now + 1;
    let maxIdx = now;
    for (let i = now + 1; i <= now + step; i++) {
      if (maxIdx < nums[i] + i) {
        maxIdx = nums[i] + i;
        nextNow = i;
      }
    }
    now = nextNow;
  }
  return answer;
}
