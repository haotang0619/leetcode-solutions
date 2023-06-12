const gcd = (a: number, b: number) => {
  return !b ? a : gcd(b, a % b);
};
const factors = (num: number) =>
  [...Array(num + 1).keys()].filter((i) => num % i === 0);

function gcdOfStrings(str1: string, str2: string): string {
  const len1 = str1.length;
  const len2 = str2.length;

  const arr = factors(gcd(len1, len2)).reverse();
  let idx = 0;
  while (!!arr[idx]) {
    const t = str1.slice(0, arr[idx]);
    const str3 = [...Array(len1 / arr[idx])].reduce((s) => `${s}${t}`, '');
    const str4 = [...Array(len2 / arr[idx])].reduce((s) => `${s}${t}`, '');
    if (str1 === str3 && str2 === str4) return t;
    idx++;
  }

  return '';
}
