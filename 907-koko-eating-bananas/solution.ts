function minEatingSpeed(piles: number[], h: number): number {
  let start = 1;
  let end = Math.max(...piles);
  let answer = end;
  while (start <= end) {
    const mid = Math.floor((start + end) / 2);
    const hours = piles.reduce((acc, p) => acc + Math.ceil(p / mid), 0);
    if (hours <= h) {
      answer = answer < mid ? answer : mid;
      end = mid - 1;
    } else start = mid + 1;
  }
  return answer;
}
