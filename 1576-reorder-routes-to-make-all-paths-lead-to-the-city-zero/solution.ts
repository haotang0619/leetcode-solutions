function minReorder(n: number, connections: number[][]): number {
  const neighbors: [number, boolean][][] = [];
  for (const [i, j] of connections) {
    if (!neighbors[i]) neighbors[i] = [];
    neighbors[i].push([j, true]);
    if (!neighbors[j]) neighbors[j] = [];
    neighbors[j].push([i, false]);
  }

  const traversal: number[] = [0];
  const visited = new Set([0]);
  let answer = 0;
  while (traversal[0] !== undefined) {
    const node = traversal.shift() as number;
    for (const [neighbor, reverse] of neighbors[node]) {
      if (!visited.has(neighbor)) {
        visited.add(neighbor);
        traversal.push(neighbor);
        answer += reverse ? 1 : 0;
      }
    }
  }
  return answer;
}
