function candy(ratings: number[]): number {
  const n = ratings.length;
  const indexes = [...Array(n).keys()].sort(
    (a, b) => ratings[a] - ratings[b] || a - b,
  );
  const result: number[] = [];
  for (let i = 0; i < n; i++) {
    const idx = indexes[i];
    let candies = 1;
    if (ratings[idx - 1] < ratings[idx]) {
      candies = Math.max(candies, result[idx - 1] + 1);
    }
    if (ratings[idx + 1] < ratings[idx]) {
      candies = Math.max(candies, result[idx + 1] + 1);
    }
    result[idx] = candies;
  }
  return result.reduce((a, b) => a + b);
}
