/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

class BTreeNode {
  val: number;
  left: BTreeNode | null;
  right: BTreeNode | null;
  constructor(val?: number, left?: BTreeNode | null, right?: BTreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

function getAllElements(
  root1: BTreeNode | null,
  root2: BTreeNode | null,
): number[] {
  const numbers: number[] = [];

  const traversal1 = [root1];
  while (!!traversal1[0]) {
    const node = traversal1.shift();
    if (!node) continue;
    numbers.push(node.val);
    if (node.left) traversal1.push(node.left);
    if (node.right) traversal1.push(node.right);
  }

  const traversal2 = [root2];
  while (!!traversal2[0]) {
    const node = traversal2.shift();
    if (!node) continue;
    numbers.push(node.val);
    if (node.left) traversal2.push(node.left);
    if (node.right) traversal2.push(node.right);
  }

  return numbers.sort((a, b) => a - b);
}
