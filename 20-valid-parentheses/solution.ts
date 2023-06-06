function isValid(s: string): boolean {
  const stack: string[] = [];
  const length = s.length;

  for (let i = 0; i < length; i++) {
    const c = s[i];
    if (['(', '[', '{'].includes(c)) {
      stack.push(c);
    } else {
      const last = stack.pop();
      if (
        (c === ')' && last !== '(') ||
        (c === ']' && last !== '[') ||
        (c === '}' && last !== '{')
      ) {
        return false;
      }
    }
  }
  return stack.length === 0;
}
