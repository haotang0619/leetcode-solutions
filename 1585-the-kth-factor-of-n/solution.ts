function kthFactor(n: number, k: number): number {
  const factors: number[][] = [[], []];
  for (let i = 1; i * i <= n; i++) {
    if (n % i === 0) {
      factors[0].push(i);
      if (i !== n / i) factors[1].unshift(n / i);
    }
  }
  return factors.flat()[k - 1] ?? -1;
}
