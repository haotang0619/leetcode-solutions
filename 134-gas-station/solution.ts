function canCompleteCircuit(gas: number[], cost: number[]): number {
  const gasSum: number[] = [];
  const costSum: number[] = [];
  const n = gas.length;
  for (let i = 0; i < n * 2; i++) {
    const j = i % n;
    gasSum[i] = (gasSum[i - 1] ?? 0) + gas[j];
    costSum[i] = (costSum[i - 1] ?? 0) + cost[j];
  }

  for (let i = 0; i < n; i++) {
    const gasShift = gasSum[i - 1] ?? 0;
    const costShift = costSum[i - 1] ?? 0;
    for (let j = i; j < i + n; j++) {
      if (gasSum[j] - gasShift < costSum[j] - costShift) {
        i = j;
        break;
      }
      if (j === i + n - 1) return i;
    }
  }
  return -1;
}
