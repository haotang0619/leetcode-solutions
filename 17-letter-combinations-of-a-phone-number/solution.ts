const digitsMapping = [
  'abc',
  'def',
  'ghi',
  'jkl',
  'mno',
  'pqrs',
  'tuv',
  'wxyz',
];

function letterRecursion(
  answer: string[],
  combination: string,
  digits: string,
): void {
  if (digits.length === 0) {
    if (!!combination) answer.push(combination);
    return;
  }
  const letters = digitsMapping[parseInt(digits[0], 10) - 2];
  letters
    .split('')
    .forEach((l) =>
      letterRecursion(answer, `${combination}${l}`, digits.slice(1)),
    );
}

function letterCombinations(digits: string): string[] {
  const answer: string[] = [];
  letterRecursion(answer, '', digits);
  return answer;
}
