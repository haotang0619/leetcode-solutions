function reverse(x: number): number {
  const min = -2147483648;
  const max = 2147483647;

  let answer = parseInt(Math.abs(x).toString().split('').reverse().join(''));
  if (x < 0) answer = -answer;
  if (answer < min || answer > max) answer = 0;
  return answer;
}
