function recursion(ans: number[][], now: number[], n: number, k: number): void {
  if (now.length === k) {
    if (n === 0) ans.push(now);
    return;
  }
  for (let i = (now[now.length - 1] || 0) + 1; i <= Math.min(9, n); i++) {
    recursion(ans, [...now, i], n - i, k);
  }
}

function combinationSum3(k: number, n: number): number[][] {
  const ans = [];
  recursion(ans, [], n, k);
  return ans;
}
