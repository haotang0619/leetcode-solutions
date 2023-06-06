function sumOfUnique(nums: number[]): number {
  const records = {};
  for (let i = 0; i < nums.length; i++) {
    records[nums[i]] = (records[nums[i]] ?? 0) + 1;
  }
  return Object.entries(records).reduce((acc, [key, val]) => {
    if (val === 1) acc += parseInt(key);
    return acc;
  }, 0);
}
