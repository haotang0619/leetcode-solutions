function isSubsequence(s: string, t: string): boolean {
  let idx = 0;
  for (let i = 0; i < t.length; i++) {
    if (s[idx] === t[i]) idx++;
    if (idx === s.length) return true;
  }
  return idx === s.length;
}
