function countCompleteComponents(n: number, edges: number[][]): number {
  const seen: Record<number, boolean> = {};
  const neighbors: Record<number, number[]> = {};

  edges.forEach(([v1, v2]) => {
    if (!neighbors[v1]) neighbors[v1] = [];
    if (!neighbors[v2]) neighbors[v2] = [];
    neighbors[v1].push(v2);
    neighbors[v2].push(v1);
  });

  let answer = 0;
  for (let i = 0; i < n; i++) {
    if (seen[i] === true) continue;
    seen[i] = true;

    const traversal = [i];
    let idx = 0;
    while (traversal[idx] !== undefined) {
      const v = traversal[idx];
      const neighborsOfV = neighbors[v] || [];
      neighborsOfV.map((nei) => {
        if (!seen[nei]) {
          traversal.push(nei);
          seen[nei] = true;
        }
      });
      idx++;
    }

    const size = traversal.length;
    answer += Number(
      traversal.every((v) => (neighbors[v] || []).length === size - 1),
    );
  }

  return answer;
}
