function firstCompleteIndex(arr: number[], mat: number[][]): number {
  const m = mat.length;
  const n = mat[0].length;

  const coordinate: number[][] = [];
  for (let r = 0; r < m; r++) {
    for (let c = 0; c < n; c++) {
      coordinate[mat[r][c]] = [r, c];
    }
  }

  const rowRecords: number[] = [];
  const colRecords: number[] = [];

  const len = arr.length;
  for (let i = 0; i < len; i++) {
    const [r, c] = coordinate[arr[i]];
    rowRecords[r] = (rowRecords[r] ?? 0) + 1;
    colRecords[c] = (colRecords[c] ?? 0) + 1;
    if (rowRecords[r] === n || colRecords[c] === m) {
      return i;
    }
  }
  return m * n;
}
