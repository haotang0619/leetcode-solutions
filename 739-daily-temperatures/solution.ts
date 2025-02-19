function dailyTemperatures(temperatures: number[]): number[] {
  const stack: [number, number][] = [];
  const answer = temperatures.map(() => 0);
  for (let i = 0; i < temperatures.length; i++) {
    while (temperatures[i] > stack[stack.length - 1]?.[1]) {
      const [idx] = stack.pop() as [number, number];
      answer[idx] = i - idx;
    }
    stack.push([i, temperatures[i]]);
  }
  return answer;
}
