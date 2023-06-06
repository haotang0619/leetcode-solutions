function colorTheArray(n: number, queries: number[][]): number[] {
  const arr = Array.from({ length: n }).map(() => 0);
  return queries.reduce((acc, cur) => {
    const [idx, color] = cur;
    let sameColor = acc.slice(-1)[0] || 0;
    if (arr[idx - 1] === arr[idx] && arr[idx] !== 0) sameColor--;
    if (arr[idx] === arr[idx + 1] && arr[idx] !== 0) sameColor--;
    arr[idx] = color;
    if (arr[idx - 1] === arr[idx]) sameColor++;
    if (arr[idx] === arr[idx + 1]) sameColor++;
    acc.push(sameColor);
    return acc;
  }, []);
}
