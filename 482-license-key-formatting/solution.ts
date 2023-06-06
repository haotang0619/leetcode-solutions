function licenseKeyFormatting(s: string, k: number): string {
  const str = s.split('-').join('').toUpperCase();
  let first = str.length % k;
  let answer = '';

  if (first > 0) answer += `${str.slice(0, first)}-`;
  while (first < str.length) {
    answer += `${str.slice(first, first + k)}-`;
    first += k;
  }
  return answer.slice(0, -1);
}
