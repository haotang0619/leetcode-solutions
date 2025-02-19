function findOrder(numCourses: number, prerequisites: number[][]): number[] {
  const adj = Array.from({ length: numCourses }).map(() => [] as boolean[]);
  const ref = Array.from({ length: numCourses }).map(() => 0);
  for (let [i, j] of prerequisites) {
    adj[j][i] = true;
    ref[i]++;
  }

  const order: number[] = [];
  for (let i = 0; i < numCourses; ++i) {
    let node = 0;
    while (node < numCourses && ref[node] !== 0) ++node;
    if (node == numCourses) return [];

    ref[node] = -1;
    order.push(node);
    for (let j = 0; j < numCourses; ++j) {
      if (adj[node][j]) ref[j]--;
    }
  }
  return order;
}
