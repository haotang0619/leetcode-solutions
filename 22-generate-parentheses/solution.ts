
function generator(
  n: number,
  leftN: number,
  now: string,
  stack: string[],
  answer: string[],
): void {
  if (stack.length === 0 && now.length === n * 2) {
    answer.push(now);
    return;
  }

  if (leftN < n) {
    generator(n, leftN + 1, `${now}(`, [...stack, '('], answer);
  }
  if (stack.length > 0) {
    stack.pop();
    generator(n, leftN, `${now})`, stack, answer);
  }
}

function generateParenthesis(n: number): string[] {
  const answer: string[] = [];
  generator(n, 0, '', [], answer);
  return answer;
}
