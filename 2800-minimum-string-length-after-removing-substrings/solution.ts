function minLength(s: string): number {
  let stack: string[] = [];
  let answer = s.length;
  for (let i = 0; i < s.length; i++) {
    if (s[i] === 'A' || s[i] === 'C') stack.push(s[i]);
    else if (
      (s[i] === 'B' && stack[stack.length - 1] === 'A') ||
      (s[i] === 'D' && stack[stack.length - 1] === 'C')
    ) {
      answer -= 2;
      stack.pop();
    } else stack = [];
  }
  return answer;
}
