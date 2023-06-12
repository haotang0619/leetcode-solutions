function findKthLargest(nums: number[], k: number): number {
  for (let i = 1; i <= 1e4; i *= 10) {
    const buckets = Array.from({ length: 10 }).map(() => [] as number[]);
    for (const num of nums) {
      const n = Math.floor(((num + 1e4) % (i * 10)) / i);
      buckets[n].push(num);
    }
    nums = buckets.flat();
  }
  return nums[nums.length - k];
}
