const getSpaces = (n: number) =>
  Array.from({ length: n }).reduce((acc, s) => `${acc} `, '');

function fullJustify(words: string[], maxWidth: number): string[] {
  const result: string[] = [];
  let now: string[] = [];
  for (let i = 0; i < words.length; i++) {
    now.push(words[i]);
    if (now.join(' ').length > maxWidth) {
      now = now.slice(0, -1);
      const len = now.join('').length;
      const space = Math.floor((maxWidth - len) / (now.length - 1));
      const extra = (maxWidth - len) % (now.length - 1);
      if (now.length === 1) result.push(`${now}${getSpaces(maxWidth - len)}`);
      else {
        result.push(
          now.reduce((acc, cur, i) => {
            const spaces =
              i === now.length - 1
                ? ''
                : getSpaces(i < extra ? space + 1 : space);
            return `${acc}${cur}${spaces}`;
          }, ''),
        );
      }
      now = [words[i]];
    }
  }
  const last = now.join(' ');
  result.push(`${last}${getSpaces(maxWidth - last.length)}`);
  return result;
}
