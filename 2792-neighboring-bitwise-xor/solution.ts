function doesValidArrayExist(derived: number[]): boolean {
  const len = derived.length;
  let answer = false;

  for (let i = 0; i <= 1; i++) {
    let now = i; // original[j]
    for (let j = 1; j < len; j++) {
      now = derived[j - 1] ^ now;
    }
    answer = (now ^ i) === derived[len - 1];
    if (answer) break;
  }

  return answer;
}
