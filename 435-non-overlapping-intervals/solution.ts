function eraseOverlapIntervals(intervals: number[][]): number {
  intervals.sort((a, b) => a[1] - b[1] || a[0] - b[0]);
  let answer = 0;
  let prev = -1e9 - 7;
  for (const [i, j] of intervals) {
    if (i >= prev) prev = j;
    else answer++;
  }
  return answer;
}
