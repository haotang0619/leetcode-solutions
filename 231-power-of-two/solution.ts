function isPowerOfTwo(n: number): boolean {
  if (n <= 0) return false;
  while (n > 1) {
    if (1 & n) return false;
    n >>= 1;
  }
  return true;
}
