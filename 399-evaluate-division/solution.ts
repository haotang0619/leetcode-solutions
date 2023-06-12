const addEdge = (
  edges: Record<string, Record<string, number>>,
  A: string,
  B: string,
  v: number,
) => {
  if (!edges[A]) edges[A] = { [A]: 1 };
  edges[A][B] = v;
  if (!edges[B]) edges[B] = { [B]: 1 };
  edges[B][A] = 1 / v;
};

function calcEquation(
  equations: string[][],
  values: number[],
  queries: string[][],
): number[] {
  const edges: Record<string, Record<string, number>> = {};
  for (const i in equations) {
    const [A, B] = equations[i];
    const v = values[i];
    addEdge(edges, A, B, v);
  }
  let answers: number[] = [];
  for (const [C, D] of queries) {
    let ans = -1;
    const traversal: [string, number][] = [[C, 1]];
    const visited = new Set<string>();
    while (traversal[0]) {
      const [node, val] = traversal.shift() as [string, number];
      const neighbors = Object.entries(edges[node] || {});
      for (const [neighbor, v] of neighbors) {
        if (!visited.has(neighbor)) {
          visited.add(neighbor);
          if (neighbor === D) {
            ans = val * v;
            break;
          }
          traversal.push([neighbor, val * v]);
        }
      }
      if (visited.has(D)) break;
    }
    answers.push(ans);
  }
  return answers;
}
