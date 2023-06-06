function plusOne(digits: number[]): number[] {
  const len = digits.length;
  let carry = 0;

  for (let i = len - 1; i >= 0; i--) {
    digits[i] += 1;
    if (digits[i] === 10) {
      digits[i] = 0;
      carry = 1;
    } else carry = 0;
    if (carry === 0) break;
  }
  if (carry === 1) {
    digits = [1, ...digits];
  }
  return digits;
}
