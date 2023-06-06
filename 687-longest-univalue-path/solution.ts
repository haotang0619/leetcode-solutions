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

// https://leetcode.com/problems/longest-univalue-path/solutions/3045413/simple-dfs-solution-beats-92-o-n-time:
function dfs(node: BTreeNode | null, answer: number[]): number {
  if (!node) return answer[0];

  let left = dfs(node.left, answer);
  let right = dfs(node.right, answer);

  if (node.left?.val !== node.val) left = 0;
  if (node.right?.val !== node.val) right = 0;
  answer[0] = Math.max(answer[0], left + right);

  return 1 + Math.max(left, right);
}

function longestUnivaluePath(root: BTreeNode | null): number {
  const answer = [0];
  dfs(root, answer);
  return answer[0];
}
