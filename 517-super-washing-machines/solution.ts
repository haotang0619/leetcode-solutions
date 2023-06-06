function findMinMoves(machines: number[]): number {
  const sum = machines.reduce((s, m) => s + m);
  const n = machines.length;
  if (sum % n !== 0) return -1;

  const target = sum / n;
  let extra = 0;

  return machines.reduce((ans, m) => {
    extra += m - target;
    return Math.max(ans, Math.abs(extra), m - target);
  }, 0);
}
