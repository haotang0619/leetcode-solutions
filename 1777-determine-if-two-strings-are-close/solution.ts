function closeStrings(word1: string, word2: string): boolean {
  const records1: Record<string, number> = {};
  for (let s of word1) records1[s] = (records1[s] ?? 0) + 1;
  const records2: Record<string, number> = {};
  for (let s of word2) records2[s] = (records2[s] ?? 0) + 1;

  const arr1 = Object.keys(records1).sort((a, b) => (a > b ? 1 : -1));
  const arr2 = Object.keys(records2).sort((a, b) => (a > b ? 1 : -1));
  const arr3 = arr1.map((k) => records1[k]).sort((a, b) => a - b);
  const arr4 = arr2.map((k) => records2[k]).sort((a, b) => a - b);
  return (
    JSON.stringify(arr1) === JSON.stringify(arr2) &&
    JSON.stringify(arr3) === JSON.stringify(arr4)
  );
}
