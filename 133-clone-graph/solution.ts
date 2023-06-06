/**
 * Definition for Node.
 * class Node {
 *     val: number
 *     neighbors: Node[]
 *     constructor(val?: number, neighbors?: Node[]) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.neighbors = (neighbors===undefined ? [] : neighbors)
 *     }
 * }
 */

class GraphNode {
  val: number;
  neighbors: GraphNode[];
  constructor(val?: number, neighbors?: GraphNode[]) {
    this.val = val === undefined ? 0 : val;
    this.neighbors = neighbors === undefined ? [] : neighbors;
  }
}

function graphRecursion(
  node: GraphNode,
  records: Record<number, GraphNode>,
): GraphNode {
  if (records[node.val]) return records[node.val];

  const newNode = new GraphNode(node.val);
  records[node.val] = newNode;
  newNode.neighbors = node.neighbors.map((n) => graphRecursion(n, records));
  return newNode;
}

function cloneGraph(node: GraphNode | null): GraphNode | null {
  const records: Record<number, GraphNode> = {};

  if (node === null) return node;
  return graphRecursion(node, records);
}
