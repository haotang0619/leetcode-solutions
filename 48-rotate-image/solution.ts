/**
 Do not return anything, modify matrix in-place instead.
 */
function rotate(matrix: number[][]): void {
  const n = matrix.length;

  for (let i = 0; i < Math.floor(n / 2); i++) {
    for (let j = i; j < n - 1 - i; j++) {
      const i1 = j,
        j1 = n - 1 - i;
      const i2 = j1,
        j2 = n - 1 - i1;
      const i3 = j2,
        j3 = n - 1 - i2;

      [matrix[i][j], matrix[i1][j1], matrix[i2][j2], matrix[i3][j3]] = [
        matrix[i3][j3],
        matrix[i][j],
        matrix[i1][j1],
        matrix[i2][j2],
      ];
    }
  }
}
