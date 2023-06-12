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

const dfs = (root: TreeNode | null) => {
  if (!root) return [];
  const leaves: number[] = [];
  const stack: TreeNode[] = [root];
  while (stack[0]) {
    const node = stack.pop() as TreeNode;
    if (node.right) stack.push(node.right);
    if (node.left) stack.push(node.left);
    if (!node.left && !node.right) leaves.push(node.val);
  }
  return leaves;
};

function leafSimilar(root1: TreeNode | null, root2: TreeNode | null): boolean {
  return JSON.stringify(dfs(root1)) === JSON.stringify(dfs(root2));
}
