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

type Traverse = { node: TreeNode; depth: number };

function maxLevelSum(root: TreeNode | null): number {
  if (!root) return 0;
  const records: number[] = [];
  const traversal: Traverse[] = [{ node: root, depth: 1 }];
  while (traversal[0]) {
    const { node, depth } = traversal.shift() as Traverse;
    records[depth] = (records[depth] ?? 0) + node.val;
    if (node.left) traversal.push({ node: node.left, depth: depth + 1 });
    if (node.right) traversal.push({ node: node.right, depth: depth + 1 });
  }
  return records.reduce(
    (acc, cur, i) => (cur > acc[1] ? [i, cur] : acc),
    [0, -1e9 - 7],
  )[0];
}
