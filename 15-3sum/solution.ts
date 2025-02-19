function threeSum(nums: number[]): number[][] {
  nums.sort((a, b) => a - b);
  const result: number[][] = [];
  let target: number | null = null;
  for (let i = nums.length - 1; i >= 2; i--) {
    if (target === -nums[i]) continue;
    target = -nums[i];
    let p1 = 0;
    let p2 = i - 1;
    while (p1 < p2) {
      const sum = nums[p1] + nums[p2];
      if (sum === target) {
        const triplet = [nums[p1], nums[p2], nums[i]];
        result.push(triplet);
        while (nums[p1] === triplet[0]) p1++;
        while (nums[p2] === triplet[1]) p2--;
      } else if (sum > target) p2--;
      else p1++;
    }
  }
  return result;
}
