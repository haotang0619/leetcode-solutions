function decodeString(s: string): string {
  const stack: [number, string][] = [[1, '']];

  for (let i = 0; i < s.length; i++) {
    if (s[i] === '[') {
      let j = i - 1;
      while (/[0-9]/.test(s[j])) j--;
      const times = parseInt(s.slice(j + 1, i));
      stack.push([times, '']);
    } else if (/[a-z]/.test(s[i])) {
      stack[stack.length - 1][1] += s[i];
    } else if (s[i] === ']') {
      let [times, str] = stack.pop() as [number, string];
      let now = '';
      while (times--) now = `${now}${str}`;
      stack[stack.length - 1][1] += now;
    }
  }
  return stack[0][1];
}
