
const mod = 10 ** 9 + 7;

function multiply(a: number, b: number) {
  if (a < b) return multiply(b, a);

  let res = 0;
  while (b) {
    if (b & 1) res = (res + a) % mod;
    a = (a * 2) % mod;
    b >>= 1;
  }
  return res;
}

function sumOfPower(nums: number[]): number {
  const len = nums.length;
  const powOf2 = [1];
  for (let i = 1; i <= len - 2; i++) {
    powOf2[i] = multiply(powOf2[i - 1], 2);
  }
  const multipliers: number[] = [];

  let answer = 0;
  nums.sort((a, b) => a - b);

  for (let i = 0; i < len; i++) {
    const square = multiply(nums[i], nums[i]);
    const multiplier =
      (nums[i] + multiply(multipliers[i - 1] ?? 0, 2) - (nums[i - 1] || 0)) %
      mod;
    multipliers[i] = multiplier;
    answer = (answer + multiply(square, multiplier)) % mod;
  }
  return answer;
}
