function equalPairs(grid: number[][]): number {
  const n = grid.length;
  const records: Record<string, { r: number; c: number }> = {};
  for (let i = 0; i < n; i++) {
    const str = JSON.stringify(grid[i]);
    if (!records[str]) records[str] = { r: 1, c: 0 };
    else records[str].r++;
  }
  let answer = 0;
  for (let i = 0; i < n; i++) {
    const col = [...Array(n).keys()].map((k) => grid[k][i]);
    const str = JSON.stringify(col);
    answer += records[str]?.r ?? 0;
  }
  return answer;
}
