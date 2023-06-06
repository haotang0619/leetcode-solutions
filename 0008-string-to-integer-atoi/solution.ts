function myAtoi(s: string): number {
  const min = -2147483648;
  const max = 2147483647;
  return Math.max(Math.min(parseInt(s) || 0, max), min);
}
