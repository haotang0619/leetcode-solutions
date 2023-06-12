function findCircleNum(isConnected: number[][]): number {
  const visited = new Set<number>();
  let answer = 0;
  for (const idx in isConnected) {
    const i = parseInt(idx);
    if (!visited.has(i)) {
      answer++;
      visited.add(i);
      const traversal: number[] = [i];
      while (traversal[0] !== undefined) {
        const city = traversal.shift() as number;
        for (const j in isConnected[city]) {
          const neighbor = parseInt(j);
          if (isConnected[city][j] && !visited.has(neighbor)) {
            visited.add(neighbor);
            traversal.push(neighbor);
          }
        }
      }
    }
  }
  return answer;
}
