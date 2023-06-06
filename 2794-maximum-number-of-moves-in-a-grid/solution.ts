
function maxMoves(grid: number[][]): number {
  const m = grid.length;
  const n = grid[0].length;

  let answer = 0;
  let available = [...Array(m).keys()];

  for (let c = 1; c <= n; c++) {
    const now: number[] = [];

    available.forEach((r) => {
      if (grid[r][c - 1] < grid[r - 1]?.[c] && !now.includes(r - 1)) {
        now.push(r - 1);
      }
      if (grid[r][c - 1] < grid[r][c] && !now.includes(r)) {
        now.push(r);
      }
      if (grid[r][c - 1] < grid[r + 1]?.[c] && !now.includes(r + 1)) {
        now.push(r + 1);
      }
    });
    available = now;

    if (available.length > 0) answer = c;
    else break;
  }

  return answer;
}
