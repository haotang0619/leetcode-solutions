function maxArea(height: number[]): number {
  const n = height.length;
  const indexes = [...Array(n).keys()].sort((a, b) => {
    return height[b] - height[a];
  });

  let answer = -1;
  let minIdx = indexes[0];
  let maxIdx = indexes[0];

  for (let i = 1; i < n; i++) {
    const idx = indexes[i];
    const maxWidth = Math.max(Math.abs(idx - maxIdx), Math.abs(idx - minIdx));
    answer = Math.max(answer, maxWidth * height[idx]);

    minIdx = Math.min(idx, minIdx);
    maxIdx = Math.max(idx, maxIdx);
  }
  return answer;
}
