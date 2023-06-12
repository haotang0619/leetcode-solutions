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

type Traverse = { node: TreeNode; max: number };

function goodNodes(root: TreeNode | null): number {
  if (!root) return 0;
  let answer = 0;
  const traversal: Traverse[] = [{ node: root, max: root.val }];
  while (traversal[0]) {
    const { node, max } = traversal.shift() as Traverse;
    let newMax = max > node.val ? max : node.val;
    if (node.left) traversal.push({ node: node.left, max: newMax });
    if (node.right) traversal.push({ node: node.right, max: newMax });
    answer += node.val === newMax ? 1 : 0;
  }
  return answer;
}
