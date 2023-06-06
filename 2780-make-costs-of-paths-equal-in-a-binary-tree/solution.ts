function minIncrements(n: number, cost: number[]): number {
  let answer = 0;

  while (n > 1) {
    const start = (n + 1) / 2 - 1;
    for (let i = start; i < n; i += 2) {
      const parent = Math.floor((i - 1) / 2);
      answer += Math.max(cost[i], cost[i + 1]) - Math.min(cost[i], cost[i + 1]);
      cost[parent] += Math.max(cost[i], cost[i + 1]);
    }
    n = (n + 1) / 2 - 1;
  }

  return answer;
}
