function kidsWithCandies(candies: number[], extraCandies: number): boolean[] {
  const max = Math.max(...candies);
  return candies.reduce(
    (acc, cur) => [...acc, cur + extraCandies >= max],
    [] as boolean[],
  );
}
