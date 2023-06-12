function summaryRanges(nums: number[]): string[] {
  let start: number | null = null;
  let answer: string[] = [];
  for (let i = 0; i <= nums.length; i++) {
    if (start === null) start = nums[i];
    else if (nums[i] !== nums[i - 1] + 1) {
      if (start < nums[i - 1]) answer.push(`${start}->${nums[i - 1]}`);
      else answer.push(`${start}`);
      start = nums[i];
    }
  }
  return answer;
}
