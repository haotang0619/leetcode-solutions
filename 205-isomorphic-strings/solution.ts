function isIsomorphic(s: string, t: string): boolean {
  const len = s.length;
  const records1: Record<string, string> = {};
  const records2: Record<string, string> = {};

  for (let i = 0; i < len; i++) {
    if (!records1[s[i]]) records1[s[i]] = t[i];
    else if (records1[s[i]] !== t[i]) return false;

    if (!records2[t[i]]) records2[t[i]] = s[i];
    else if (records2[t[i]] !== s[i]) return false;
  }
  return true;
}
