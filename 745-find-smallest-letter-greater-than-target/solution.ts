function nextGreatestLetter(letters: string[], target: string): string {
  let answer = '';
  const targetCode = target.charCodeAt(0);
  for (let l of letters) {
    if (l.charCodeAt(0) > targetCode) {
      answer = l;
      break;
    }
  }
  return answer || letters[0];
}
