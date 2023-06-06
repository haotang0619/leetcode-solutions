function repeatedStringMatch(a: string, b: string): number {
  const m = a.length;
  const n = b.length;

  let c = `${a}${a}`;
  while (c.length < 2 * n) c = `${c}${a}`;
  const len = c.length;

  let pos = -1;
  for (let i = 0; i < len; i++) {
    if (c.slice(i, i + n) === b) {
      pos = i + n;
      break;
    }
  }

  if (pos === -1) return -1;
  return Math.ceil(pos / m);
}
