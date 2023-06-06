function addEdge(neighbors: Record<number, number[]>, a: number, b: number) {
  if (!neighbors[a]) neighbors[a] = [];
  if (!neighbors[b]) neighbors[b] = [];

  neighbors[a].push(b);
  neighbors[b].push(a);
}

function shortestPath(
  neighbors: Record<number, number[]>,
  a: number,
  b: number,
) {
  if (a === b) return 0;
  const visited = new Set();

  const traversal = [{ idx: a, depth: 0 }];
  while (!!traversal[0]) {
    const { idx, depth } = traversal.shift() as { idx: number; depth: number };
    visited.add(idx);

    const neighborOfIdx = neighbors[idx] || [];
    const len = neighborOfIdx.length;
    for (let i = 0; i < len; i++) {
      const neighbor = neighborOfIdx[i];
      if (!visited.has(neighbor)) {
        if (neighbor === b) return depth + 1;
        visited.add(neighbor);
        traversal.push({ idx: neighbor, depth: depth + 1 });
      }
    }
  }

  return -1;
}

function cutOffTree(forest: number[][]): number {
  const nodes: number[] = [];
  const neighbors: Record<number, number[]> = {};

  const m = forest.length;
  const n = forest[0].length;
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      const a = i * n + j;
      nodes.push(forest[i][j]);
      if (forest[i][j] > 0 && forest[i - 1]?.[j] > 0) {
        const b = (i - 1) * n + j;
        addEdge(neighbors, a, b);
      }
      if (forest[i][j] > 0 && forest[i][j - 1] > 0) {
        const b = i * n + (j - 1);
        addEdge(neighbors, a, b);
      }
    }
  }

  const indexes = [...Array(m * n).keys()]
    .sort((a, b) => {
      return nodes[a] - nodes[b];
    })
    .filter((i) => nodes[i] > 1);

  let answer = 0;

  const len = indexes.length;
  for (let i = -1; i < len - 1; i++) {
    const distance = shortestPath(neighbors, indexes[i] || 0, indexes[i + 1]);
    if (distance === -1) return -1;
    answer += distance;
  }

  return answer;
}
