function merge(intervals: number[][]): number[][] {
  const sorted = intervals.sort((a, b) => a[0] - b[0]);
  let now: number[] = [];
  const answer: number[][] = [];

  sorted.forEach(([start, end]) => {
    if (now.length === 0) now = [start, end];
    else if (start <= now[1]) {
      now = [now[0], Math.max(end, now[1])];
    } else {
      answer.push(now);
      now = [start, end];
    }
  });
  answer.push(now);

  return answer;
}
