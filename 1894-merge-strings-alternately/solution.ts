function mergeAlternately(word1: string, word2: string): string {
  let idx = 0;
  let answer = '';
  while (!!word1[idx] || !!word2[idx]) {
    answer += (word1[idx] || '') + (word2[idx] || '');
    idx++;
  }
  return answer;
}
