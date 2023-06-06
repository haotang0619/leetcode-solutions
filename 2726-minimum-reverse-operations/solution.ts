
// BFS

class Visited {
  private evenRange: [number, number][];
  private oddRange: [number, number][];

  constructor(p: number) {
    this.evenRange = p % 2 === 0 ? [[p, p]] : [];
    this.oddRange = p % 2 === 1 ? [[p, p]] : [];
  }

  add(nums: [number, number]) {
    const range = nums[0] % 2 === 0 ? this.evenRange : this.oddRange;
    range.push(nums);
    range.sort((a, b) => a[0] - b[0]);

    const newRange = [range[0]];
    let idx = 0;
    for (let i = 1; i < range.length; i++) {
      if (newRange[idx][1] >= range[i][0]) {
        newRange[idx][1] = Math.max(newRange[idx][1], range[i][1]);
      } else newRange[++idx] = range[i];
    }

    if (nums[0] % 2 === 0) this.evenRange = newRange;
    else this.oddRange = newRange;
  }

  has(num: number) {
    const range = num % 2 === 0 ? this.evenRange : this.oddRange;
    return range.some(([a, b]) => a <= num && b >= num);
  }

  next(num: number) {
    const range = num % 2 === 0 ? this.evenRange : this.oddRange;
    const upper = range.find(([a, b]) => a <= num && b >= num)?.[1];
    return (upper ?? num) + 2;
  }
}

function minReverseOperations(
  n: number,
  p: number,
  banned: number[],
  k: number,
): number[] {
  const bannedSet = new Set(banned);
  const visited = new Visited(p);

  const answer: number[] = [];
  const traversal: { idx: number; depth: number }[] = [{ idx: p, depth: 0 }];
  let pos = 0;
  while (!!traversal[pos]) {
    const { idx, depth } = traversal[pos];
    answer[idx] = depth;

    const start = Math.max(0, idx - k + 1);
    const end = Math.min(idx + k, n) - k;
    const startIdx = start + (start + k - 1) - idx;
    const endIdx = end + (end + k - 1) - idx;

    for (let i = startIdx; i <= endIdx; i = visited.next(i)) {
      if (!bannedSet.has(i) && !visited.has(i)) {
        traversal.push({ idx: i, depth: depth + 1 });
      }
    }

    visited.add([startIdx, endIdx]);
    pos++;
  }

  for (let i = 0; i < n; i++) answer[i] = answer[i] ?? -1;
  return answer;
}
