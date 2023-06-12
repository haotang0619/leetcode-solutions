function maxProfit(prices: number[]): number {
  let p1 = 0;
  let p2 = 1;
  let answer = 0;

  while (p2 < prices.length) {
    answer = Math.max(answer, prices[p2] - prices[p1]);
    if (prices[p2] <= prices[p1]) p1 = p2;
    p2++;
  }
  return answer;
}
