function wordBreak(s: string, wordDict: string[]): boolean {
  const len = s.length;
  const records: boolean[] = [];

  for (let i = 1; i <= len; i++) {
    records[i] = false;
    wordDict.forEach((word) => {
      const start = i - word.length;
      const chunk = s.slice(Math.max(start, 0), i);
      if (chunk === word) {
        records[i] ||= records[start] ?? true;
      }
    });
  }
  return records[len];
}
