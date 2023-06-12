const addEdge = (edges: Record<string, string[]>, A: string, B: string) => {
  if (!edges[A]) edges[A] = [];
  if (!edges[B]) edges[B] = [];
  edges[A].push(B);
  edges[B].push(A);
};
const getNode = (i: number, j: number) => `${i},${j}`;

type Traverse = { node: string; depth: number };

function orangesRotting(grid: number[][]): number {
  const visited = new Set<string>();
  const edges: Record<string, string[]> = {};

  const traversal: Traverse[] = [];
  let freshCnt = 0;

  const m = grid.length;
  const n = grid[0].length;
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] === 0) continue;
      else if (grid[i][j] === 1) freshCnt++;
      else {
        traversal.push({ node: getNode(i, j), depth: 0 });
        visited.add(getNode(i, j));
      }

      if (grid[i - 1]?.[j] > 0) {
        addEdge(edges, getNode(i - 1, j), getNode(i, j));
      }
      if (grid[i][j - 1] > 0) {
        addEdge(edges, getNode(i, j - 1), getNode(i, j));
      }
    }
  }
  if (freshCnt === 0) return 0;

  while (traversal[0]) {
    const { node, depth } = traversal.shift() as Traverse;
    const neighbors = edges[node] || [];
    for (const neighbor of neighbors) {
      if (!visited.has(neighbor)) {
        freshCnt--;
        if (freshCnt === 0) return depth + 1;
        traversal.push({ node: neighbor, depth: depth + 1 });
        visited.add(neighbor);
      }
    }
  }
  return -1;
}
