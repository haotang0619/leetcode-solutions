function predictPartyVictory(senate: string): string {
  const stack: string[] = [];
  const len = senate.length;
  let rCount = senate.match(/R/g)?.length || 0;
  let dCount = len - rCount;
  let banned = new Set<number>();

  while (true) {
    if (rCount === 0) return 'Dire';
    if (dCount === 0) return 'Radiant';
    for (let i = 0; i < len; i++) {
      if (banned.has(i)) continue;
      const sen = senate[i];
      if (stack.length === 0 || stack[0] === sen) stack.push(sen);
      else {
        banned.add(i);
        sen === 'R' ? rCount-- : dCount--;
        stack.pop();
      }
    }
  }
}
