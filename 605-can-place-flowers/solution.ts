function canPlaceFlowers(flowerbed: number[], n: number): boolean {
  let idx = 0;
  while (n > 0) {
    while (
      flowerbed
        .slice(Math.max(idx - 1, 0), Math.min(idx + 2, flowerbed.length))
        .includes(1)
    ) {
      idx++;
    }
    if (idx < flowerbed.length) {
      flowerbed[idx] = 1;
      n--;
    } else break;
  }
  return n === 0;
}
