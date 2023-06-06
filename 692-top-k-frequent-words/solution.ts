function topKFrequent(words: string[], k: number): string[] {
  const records: Record<string, number> = {};
  words.forEach((word) => {
    records[word] = (records[word] || 0) + 1;
  });

  const result = Object.keys(records).sort((a, b) => {
    if (records[a] === records[b]) {
      return a > b ? 1 : -1;
    }
    return records[b] - records[a];
  });
  console.log('TCL: result', result);

  return result.slice(0, k);
}
