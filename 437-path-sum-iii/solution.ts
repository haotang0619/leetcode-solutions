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

type Traverse = { node: TreeNode; prefixSum: number[] };

function pathSum(root: TreeNode | null, targetSum: number): number {
  if (!root) return 0;
  let answer = 0;
  const traversal: Traverse[] = [{ node: root, prefixSum: [] }];
  while (traversal[0]) {
    const { node, prefixSum } = traversal.shift() as Traverse;
    const newSum = [...prefixSum, 0].map((p) => {
      const sum = p + node.val;
      if (sum === targetSum) answer++;
      return sum;
    });
    if (node.left) traversal.push({ node: node.left, prefixSum: newSum });
    if (node.right) traversal.push({ node: node.right, prefixSum: newSum });
  }
  return answer;
}
