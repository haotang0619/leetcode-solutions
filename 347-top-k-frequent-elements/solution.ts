function topKFrequent(nums: number[], k: number): number[] {
  const records: Record<number, number> = {};
  nums.forEach((num) => {
    records[num] = (records[num] ?? 0) + 1;
  });
  return Object.entries(records)
    .sort((a, b) => b[1] - a[1])
    .slice(0, k)
    .map(([num]) => parseInt(num));
}
