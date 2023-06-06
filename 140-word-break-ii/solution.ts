function wordBreak(s: string, wordDict: string[]): string[] {
  const len = s.length;
  const records: string[][] = [];

  for (let i = 1; i <= len; i++) {
    records[i] = [];
    wordDict.forEach((word) => {
      const start = i - word.length;
      const chunk = s.slice(Math.max(start, 0), i);
      if (chunk === word) {
        if (start < 1) {
          records[i].push(word);
        } else {
          records[i].push(...records[start].map((rec) => `${rec} ${word}`));
        }
      }
    });
  }

  return records[len];
}
