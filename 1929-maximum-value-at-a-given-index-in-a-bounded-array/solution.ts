function maxValue(n: number, index: number, maxSum: number): number {
  let start = 1;
  let end = maxSum;
  let answer = -1;
  while (start <= end) {
    const mid = Math.floor((start + end) / 2);
    let sum = Math.max(0, index + 1 - mid) + Math.max(0, n - index - mid);
    const leftStart = Math.max(1, mid - index);
    sum += ((leftStart + mid) * (mid - leftStart + 1)) / 2;
    const rightStart = Math.max(1, mid - (n - index - 1));
    sum += ((rightStart + mid) * (mid - rightStart + 1)) / 2;
    sum -= mid;
    if (sum <= maxSum) {
      answer = answer > mid ? answer : mid;
      start = mid + 1;
    } else end = mid - 1;
  }
  return answer;
}
