/**
 * Definition for Node.
 * class Node {
 *     val: number
 *     left: Node | null
 *     right: Node | null
 *     next: Node | null
 *     constructor(val?: number, left?: Node, right?: Node, next?: Node) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

class TNode {
  val: number;
  left: TNode | null;
  right: TNode | null;
  next: TNode | null;
  constructor(val?: number, left?: TNode, right?: TNode, next?: TNode) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
    this.next = next === undefined ? null : next;
  }
}

function connect(root: TNode | null): TNode | null {
  if (!root) return root;
  const traversal = [{ node: root, depth: 0 }];

  let idx = 0;
  while (!!traversal[idx]) {
    const { node, depth } = traversal[idx];
    if (node.left) traversal.push({ node: node.left, depth: depth + 1 });
    if (node.right) traversal.push({ node: node.right, depth: depth + 1 });
    if (traversal[idx - 1]?.depth === depth) {
      traversal[idx - 1].node.next = node;
    }
    idx++;
  }

  return root;
}
