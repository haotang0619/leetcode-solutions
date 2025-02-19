function minFlips(a: number, b: number, c: number): number {
  let answer = 0;
  for (let i = 0; i < 30; i++) {
    if ((c >> i) & 1 && !((a >> i) & 1) && !((b >> i) & 1)) answer++;
    if (!((c >> i) & 1)) answer += ((a >> i) & 1) + ((b >> i) & 1);
  }
  return answer;
}
