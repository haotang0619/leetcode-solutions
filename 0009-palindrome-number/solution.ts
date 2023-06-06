function isPalindrome(x: number): boolean {
  const s = x.toString();
  for (let i = 0; i < s.length; i++) {
    if (s[i] !== s[s.length - 1 - i]) return false;
  }
  return true;
}
