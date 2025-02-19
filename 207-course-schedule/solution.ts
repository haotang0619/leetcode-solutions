function canFinish(numCourses: number, prerequisites: number[][]): boolean {
  const edges: number[][] = [];
  prerequisites.forEach(([a, b]) => {
    if (!edges[b]) edges[b] = [];
    edges[b].push(a);
  });
  const seen = new Set();
  for (let i = 0; i < numCourses; i++) {
    if (seen.has(i)) continue;
    seen.add(i);
    const stack = [{ node: i, visited: new Set([i]) }];
    while (!!stack[0]) {
      const { node, visited } = stack.pop() as {
        node: number;
        visited: Set<number>;
      };
      const courses = edges[node] || [];
      for (let c of courses) {
        if (visited.has(c)) return false;
        if (!seen.has(c)) {
          seen.add(c);
          stack.push({ node: c, visited: new Set([...visited, c]) });
        }
      }
    }
  }
  return true;
}
