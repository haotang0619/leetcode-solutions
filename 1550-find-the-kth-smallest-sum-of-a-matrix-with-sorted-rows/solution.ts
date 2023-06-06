function kthSmallest(mat: number[][], k: number): number {
  const m = mat.length;
  const n = mat[0].length;
  let result = [...mat[0]];

  for (let i = 1; i < m; i++) {
    const newRes: number[] = [];
    for (let j = 0; j < n; j++) {
      newRes.push(...result.map((r) => r + mat[i][j]));
    }
    result = newRes.sort((a, b) => a - b).slice(0, k);
  }
  return result[k - 1];
}
