function lengthOfLongestSubstring(s: string): number {
  const records: Record<string, boolean> = {};
  let p1 = 0;
  let p2 = 0;
  let answer = 0;
  const len = s.length;

  while (p2 < len) {
    if (!records[s[p2]]) records[s[p2]] = true;
    else {
      answer = Math.max(answer, p2 - p1);
      while (s[p1] !== s[p2]) {
        delete records[s[p1]];
        p1++;
      }
      p1++;
    }
    p2++;
  }
  answer = Math.max(answer, p2 - p1);

  return answer;
}
