function insert(intervals: number[][], newInterval: number[]): number[][] {
  let now: number[] = [];
  const answer: number[][] = [];
  let len = intervals.length;
  let flag = false;

  if (newInterval[0] >= (intervals[len - 1]?.[0] ?? -1)) {
    intervals.push(newInterval);
    len += 1;
  }

  for (let i = 0; i < len; i++) {
    let [start, end] = intervals[i];
    if (newInterval[0] < start && flag === false) {
      start = newInterval[0];
      end = newInterval[1];
      flag = true;
      i--;
    }

    if (now.length === 0) now = [start, end];
    else if (start <= now[1]) {
      now = [now[0], Math.max(end, now[1])];
    } else {
      answer.push(now);
      now = [start, end];
    }
  }
  answer.push(now);

  return answer;
}
