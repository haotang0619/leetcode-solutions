function findLongestChain(pairs: number[][]): number {
  pairs.sort((a, b) => a[1] - b[1] || a[0] - b[0]);

  let answer = 0;
  const len = pairs.length;
  let now = -1001;
  for (let i = 0; i < len; i++) {
    if (now < pairs[i][0]) {
      answer += 1;
      now = pairs[i][1];
    }
  }

  return answer;
}
