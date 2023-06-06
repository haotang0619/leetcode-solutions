function spiralOrder(matrix: number[][]): number[] {
  let minI = 0;
  let minJ = 0;
  let maxI = matrix.length - 1;
  let maxJ = matrix[0].length - 1;
  let direction = 'right';

  const answer: number[] = [];

  while (minI <= maxI && minJ <= maxJ) {
    if (direction === 'right') {
      for (let j = minJ; j <= maxJ; j++) {
        answer.push(matrix[minI][j]);
      }
      direction = 'down';
      minI += 1;
    } else if (direction === 'down') {
      for (let i = minI; i <= maxI; i++) {
        answer.push(matrix[i][maxJ]);
      }
      direction = 'left';
      maxJ -= 1;
    } else if (direction === 'left') {
      for (let j = maxJ; j >= minJ; j--) {
        answer.push(matrix[maxI][j]);
      }
      direction = 'up';
      maxI -= 1;
    } else {
      for (let i = maxI; i >= minI; i--) {
        answer.push(matrix[i][minJ]);
      }
      direction = 'right';
      minJ += 1;
    }
  }

  return answer;
}
