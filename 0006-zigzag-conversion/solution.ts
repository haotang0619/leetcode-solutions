function convert(s: string, numRows: number): string {
  const records: number[] = [];
  let idx = 0;

  for (let i = 0; i < s.length; i++) {
    records[i] = idx;
    if (numRows === 1) continue;
    if (idx === 0) idx++;
    else if (idx === numRows - 1) idx--;
    else if (records[i - 1] < records[i]) idx++;
    else idx--;
  }

  const str = Array.from({ length: numRows }).map(() => '');
  for (let i = 0; i < s.length; i++) {
    str[records[i]] += s[i];
  }
  return str.join('');
}
