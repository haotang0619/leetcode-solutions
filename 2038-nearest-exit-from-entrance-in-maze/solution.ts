const addEdge = (edges: Record<string, string[]>, A: string, B: string) => {
  if (!edges[A]) edges[A] = [];
  edges[A].push(B);
  if (!edges[B]) edges[B] = [];
  edges[B].push(A);
};

function nearestExit(maze: string[][], entrance: number[]): number {
  const m = maze.length;
  const n = maze[0].length;

  const edges: Record<string, string[]> = {};
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (maze[i][j] !== '.') continue;
      if (maze[i - 1]?.[j] === '.') {
        addEdge(edges, `${i - 1},${j}`, `${i},${j}`);
      }
      if (maze[i][j - 1] === '.') {
        addEdge(edges, `${i},${j - 1}`, `${i},${j}`);
      }
    }
  }

  const entranceNode = `${entrance[0]},${entrance[1]}`;
  const traversal: { node: string; depth: number }[] = [
    { node: entranceNode, depth: 0 },
  ];
  const visited = new Set([entranceNode]);
  while (traversal[0]) {
    const { node, depth } = traversal.shift() as { node: string; depth: 0 };
    const neighbors = edges[node] || [];
    for (const neighbor of neighbors) {
      if (!visited.has(neighbor)) {
        const [i, j] = neighbor.split(',').map((s) => parseInt(s));
        if ([0, m - 1].includes(i) || [0, n - 1].includes(j)) {
          return depth + 1;
        }
        visited.add(neighbor);
        traversal.push({ node: neighbor, depth: depth + 1 });
      }
    }
  }
  return -1;
}
