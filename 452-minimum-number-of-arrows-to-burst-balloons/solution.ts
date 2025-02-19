function findMinArrowShots(points: number[][]): number {
  const sorted = points.sort((a, b) => a[0] - b[0]);
  let now: number[] = [];
  let answer = 0;

  sorted.forEach(([start, end]) => {
    if (now.length === 0) now = [start, end];
    else if (start <= now[1]) {
      now = [Math.max(start, now[0]), Math.min(end, now[1])];
    } else {
      answer++;
      now = [start, end];
    }
  });
  answer++;

  return answer;
}
