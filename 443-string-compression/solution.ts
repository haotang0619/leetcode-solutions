function compress(chars: string[]): number {
  let now = chars[0];
  let cnt = 1;
  let answer = 0;
  let idx = 0;
  for (let i = 1; i < chars.length + 1; i++) {
    if (chars[i] !== now) {
      const cntStr = cnt === 1 ? '' : cnt.toString();
      answer += 1 + cntStr.length;
      `${now}${cntStr}`.split('').forEach((c) => (chars[idx++] = c));
      now = chars[i];
      cnt = 1;
    } else cnt++;
  }

  return answer;
}
