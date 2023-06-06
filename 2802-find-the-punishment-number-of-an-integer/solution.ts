function isPunishmentElement(sum: number, str: string): boolean {
  if (sum === 0 && str.length === 0) return true;

  const maxLen = Math.min(str.length, sum.toString().length);
  let answer = false;

  for (let i = 1; i <= maxLen; i++) {
    const n = parseInt(str.slice(0, i), 10);
    answer ||= isPunishmentElement(sum - n, str.slice(i));
  }

  return answer;
}

function getPunishmentElements(): number[] {
  const answer: number[] = [];
  for (let i = 1; i <= 1000; i++) {
    if (isPunishmentElement(i, (i * i).toString())) {
      answer.push(i);
    }
  }
  return answer;
}

const punishmentElements = getPunishmentElements();

function punishmentNumber(n: number): number {
  let answer = 0;

  for (let i = 1; i <= n; i++) {
    if (punishmentElements.includes(i)) answer += i * i;
  }

  return answer;
}
