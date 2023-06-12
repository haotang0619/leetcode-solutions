function maxArea(height: number[]): number {
  let p1 = 0;
  let p2 = height.length - 1;
  let answer = -1;
  while (p1 < p2) {
    answer = Math.max(answer, (p2 - p1) * Math.min(height[p1], height[p2]));
    if (height[p1] < height[p2]) p1++;
    else if (height[p1] > height[p2]) p2--;
    else p1++, p2--;
  }

  return answer;
}
