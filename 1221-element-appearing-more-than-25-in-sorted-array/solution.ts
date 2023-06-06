function findSpecialInteger(arr: number[]): number {
  const n = arr.length;
  const target = n / 4;

  const records = {};
  for (let i = 0; i < n; i++) {
    records[arr[i]] = (records[arr[i]] ?? 0) + 1;
    if (records[arr[i]] > target) return arr[i];
  }
  return 0;
}
