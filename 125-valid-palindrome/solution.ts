function isPalindrome(s: string): boolean {
  const str = s.replace(/[^0-9a-z]/gi, '').toLowerCase();
  return str === str.split('').reverse().join('');
}
