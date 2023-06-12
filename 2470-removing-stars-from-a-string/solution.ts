function removeStars(s: string): string {
  let ans = '';
  let cnt = 0;
  for (let i = s.length - 1; i >= 0; i--) {
    if (s[i] === '*') cnt++;
    else if (cnt > 0) cnt--;
    else ans = s[i] + ans;
  }
  return ans;
}
