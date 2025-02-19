const answer: number[] = [];

function countBits(n: number): number[] {
  for (let i = 0; i <= n; i++) {
    let now = i;
    let cnt = 0;
    while (now > 0) {
      if (answer[now]) {
        cnt += answer[now];
        break;
      }
      cnt += now & 1;
      now >>= 1;
    }
    answer[i] = cnt;
  }
  return answer.slice(0, n + 1);
}
