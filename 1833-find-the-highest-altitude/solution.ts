function largestAltitude(gain: number[]): number {
  let now = 0;
  let answer = 0;
  for (let i = 0; i < gain.length; i++) {
    now += gain[i];
    answer = answer > now ? answer : now;
  }
  return answer;
}
