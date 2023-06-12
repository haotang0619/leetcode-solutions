const vowels = ['a', 'e', 'i', 'o', 'u'];

function maxVowels(s: string, k: number): number {
  const len = s.length;
  let answer = 0;
  let now = 0;

  for (let i = 0; i < len; i++) {
    if (vowels.includes(s[i - k])) now--;
    if (vowels.includes(s[i])) now++;
    answer = Math.max(answer, now);
  }

  return answer;
}
