function maxProfit(prices: number[]): number {
  let hold = prices[0];
  let answer = 0;
  for (let i = 1; i < prices.length; i++) {
    if (prices[i] > hold) answer += prices[i] - hold;
    hold = prices[i];
  }
  return answer;
}
