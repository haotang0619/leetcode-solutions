
const MAX_COST = 1e6;

function getCost(start: number[], target: number[]) {
  return Math.abs(start[0] - target[0]) + Math.abs(start[1] - target[1]);
}

function shortestPath(adjacency: number[][], start: number, target: number) {
  const length = adjacency.length;
  const distance = Array.from({ length }).map(() => MAX_COST);
  adjacency[start].forEach((dis, i) => (distance[i] = dis ?? 0));
  const visited = new Set([start]);

  while (visited.size < length) {
    let closest = MAX_COST;
    let idx = 0;
    for (let i = 0; i < length; i++) {
      if (distance[i] <= closest && !visited.has(i)) {
        idx = i;
        closest = distance[i];
      }
    }
    if (idx === target) break;

    visited.add(idx);
    adjacency[idx].forEach((dis, i) => {
      if (!visited.has(i)) {
        distance[i] = Math.min(distance[i], distance[idx] + adjacency[idx][i]);
      }
    });
  }

  return distance[target];
}

function minimumCost(
  start: number[],
  target: number[],
  specialRoads: number[][],
): number {
  const length = specialRoads.length * 2 + 2;
  const adjacency: number[][] = Array.from({ length }).map(() => []);
  adjacency[0][1] = getCost(start, target);

  const len = specialRoads.length;
  for (let i = 0; i < len; i++) {
    adjacency[0][i * 2 + 2] = getCost(start, specialRoads[i].slice(0, 2));
    adjacency[i * 2 + 2][i * 2 + 3] = Math.min(
      getCost(specialRoads[i].slice(0, 2), specialRoads[i].slice(2, 4)),
      specialRoads[i][4],
    );
    adjacency[i * 2 + 3][1] = getCost(specialRoads[i].slice(2, 4), target);
    for (let j = 0; j < len; j++) {
      if (i === j) continue;
      adjacency[i * 2 + 3][j * 2 + 2] = getCost(
        specialRoads[i].slice(2, 4),
        specialRoads[j].slice(0, 2),
      );
    }
  }

  return shortestPath(adjacency, 0, 1);
}
