const aCode = 'a'.charCodeAt(0);

function addByOne(c: string, k: number): string {
  const code = c.charCodeAt(0) + 1;
  if (code >= aCode + k) return '';
  return String.fromCharCode(code);
}

// https://leetcode.com/problems/lexicographically-smallest-beautiful-string/solutions/3468344/python-different-three-continuous-character:
function smallestBeautifulString(s: string, k: number): string {
  let str = s.split('');
  const len = s.length;
  let i = len - 1;

  while (i >= 0) {
    str[i] = addByOne(str[i], k);
    if (!str[i]) {
      i--;
      continue;
    }

    if (str[i] !== str[i - 1] && str[i] !== str[i - 2]) {
      for (let j = i + 1; j < len; j++) {
        str[j] = 'a';
        if (str[j] === str[j - 1] || str[j] === str[j - 2]) str[j] = 'b';
        if (str[j] === str[j - 1] || str[j] === str[j - 2]) str[j] = 'c';
      }
      break;
    }
  }

  return str.join('');
}
