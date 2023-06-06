function numJewelsInStones(jewels: string, stones: string): number {
  return stones.split('').filter((s) => jewels.includes(s)).length;
}
