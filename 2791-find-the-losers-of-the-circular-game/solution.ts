function circularGameLosers(n: number, k: number): number[] {
  const records = { 1: 1 };
  for (let i = 2; i <= n; i++) records[i] = 0;
  let now = 1;
  let i = 1;
  while (true) {
    now = (now + i * k) % n;
    now = now === 0 ? n : now;
    if (records[now] === 1) break;
    records[now] = 1;
    i++;
  }
  const answer: number[] = [];
  for (let i = 2; i <= n; i++) records[i] === 0 ? answer.push(i) : null;
  return answer;
}
