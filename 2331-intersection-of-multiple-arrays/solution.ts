function intersection(nums: number[][]): number[] {
  nums.sort((a, b) => b.length - a.length);
  return nums[0]
    .reduce((acc, cur) => {
      if (nums.every((n) => n.includes(cur))) acc.push(cur);
      return acc;
    }, [] as number[])
    .sort((a, b) => a - b);
}
