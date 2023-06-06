function romanToInt(s: string): number {
  let answer = 0;
  let idx = 0;
  const special = { CM: 900, CD: 400, XC: 90, XL: 40, IX: 9, IV: 4 };
  const normal = { M: 1000, D: 500, C: 100, L: 50, X: 10, V: 5, I: 1 };

  while (idx < s.length) {
    const now = special[s.slice(idx, idx + 2)];
    if (now > 0) {
      answer += now;
      idx += 2;
    } else answer += normal[s[idx++]];
  }
  return answer;
}
