function hIndex(citations: number[]): number {
  citations.sort((a, b) => b - a);
  const n = citations.length;
  for (let i = 0; i < n; i++) {
    if (i + 1 >= citations[i]) return Math.max(i, citations[i]);
  }
  return citations.length;
}
