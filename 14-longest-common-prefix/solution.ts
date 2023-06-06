function longestCommonPrefix(strs: string[]): string {
  if (strs.length === 1) return strs[0];
  strs.sort((a, b) => b.length - a.length);

  for (let i = strs[0].length; i >= 0; i--) {
    const prefix = strs[0].slice(0, i);
    if (strs.every((s) => s.slice(0, i) === prefix)) {
      return prefix;
    }
  }
  return '';
}
