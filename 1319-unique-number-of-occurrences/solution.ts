function uniqueOccurrences(arr: number[]): boolean {
  const records1: Record<number, number> = {};
  for (let num of arr) records1[num] = (records1[num] ?? 0) + 1;
  const records2: Record<number, boolean> = {};
  for (let key in records1) {
    const num = records1[key];
    if (records2[num]) return false;
    records2[num] = true;
  }
  return true;
}
