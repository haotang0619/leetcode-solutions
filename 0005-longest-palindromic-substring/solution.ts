function longestPalindrome(s: string): string {
  let max = 0;
  let answer = '';
  const n = s.length;

  for (let i = 0; i < n; i++) {
    for (let j = i; i - (j - i) >= 0 && j < n; j++) {
      if (s[j] === s[i - (j - i)]) {
        max = Math.max((j - i) * 2 + 1, max);
        if (max === (j - i) * 2 + 1) {
          answer = s.slice(i - (j - i), j + 1);
        }
      } else break;
    }

    for (let j = i + 1; i - (j - i - 1) >= 0 && j < n; j++) {
      if (s[j] === s[i - (j - i - 1)]) {
        max = Math.max((j - i) * 2, max);
        if (max === (j - i) * 2) {
          answer = s.slice(i - (j - i - 1), j + 1);
        }
      } else break;
    }
  }
  return answer;
}
