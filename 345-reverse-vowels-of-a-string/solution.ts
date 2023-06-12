function reverseVowels(s: string): string {
  const arr = s.split(/[aeiou]/i);
  const vowels = s
    .split('')
    .filter((c) => /[aeiou]/i.test(c))
    .reverse();
  return arr.reduce((a, b, i) => `${a}${vowels[i - 1]}${b}`);
}
