function makeSmallestPalindrome(s: string): string {
  const n = s.length;
  const mid = Math.floor(n / 2);
  let answer = 0;
  let arr: string[] = [];
  for (let i = mid; i >= 0; i--) {
    let c = s[i];
    if (s[i] > s[n - 1 - i]) c = s[n - 1 - i];
    arr[i] = arr[n - 1 - i] = c;
  }
  return arr.join('');
}
