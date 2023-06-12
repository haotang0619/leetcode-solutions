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

function rightSideView(root: TreeNode | null): number[] {
  if (!root) return [];
  const answer: number[] = [];
  const traversal: Traverse[] = [{ node: root, depth: 0 }];
  while (traversal[0]) {
    const { node, depth } = traversal.shift() as Traverse;
    answer[depth] = node.val;
    if (node.left) traversal.push({ node: node.left, depth: depth + 1 });
    if (node.right) traversal.push({ node: node.right, depth: depth + 1 });
  }
  return answer;
}
