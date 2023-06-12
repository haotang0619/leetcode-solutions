function successfulPairs(
  spells: number[],
  potions: number[],
  success: number,
): number[] {
  potions.sort((a, b) => b - a);
  return spells.map((spell) => {
    const target = success / spell;
    let start = 0;
    let end = potions.length - 1;
    let mid = Math.floor((start + end) / 2);
    while (start <= end) {
      if (
        potions[mid] >= target &&
        (potions[mid + 1] < target || mid + 1 === potions.length)
      ) {
        break;
      }
      if (potions[mid] >= target) start = mid + 1;
      else if (mid === 0) {
        mid = -1;
        break;
      } else end = mid;
      mid = Math.floor((start + end) / 2);
    }
    return mid + 1;
  });
}
