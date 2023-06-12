const arr = [0, 1, 1];
for (let i = 3; i <= 37; i++) arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];

function tribonacci(n: number): number {
  return arr[n];
}
