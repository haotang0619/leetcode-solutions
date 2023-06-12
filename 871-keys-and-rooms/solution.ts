function canVisitAllRooms(rooms: number[][]): boolean {
  const visited = new Set<number>([0]);
  const traversal: number[] = [0];
  while (traversal[0] !== undefined) {
    const room = traversal.shift() as number;
    for (const neighbor of rooms[room]) {
      if (!visited.has(neighbor)) {
        visited.add(neighbor);
        traversal.push(neighbor);
      }
    }
  }
  return visited.size === rooms.length;
}
