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
class TNode {
  val: number;
  left: TNode | null;
  right: TNode | null;
  constructor(val?: number, left?: TNode | null, right?: TNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

const traversal = (arr: number[], node: TNode) => {
  if (node.left) traversal(arr, node.left);
  arr.push(node.val);
  if (node.right) traversal(arr, node.right);
};

function getMinimumDifference(root: TNode): number {
  const arr: number[] = [];
  traversal(arr, root);
  let ans = arr[1] - arr[0];
  for (let i = 2; i < arr.length; i++) {
    ans = ans < arr[i] - arr[i - 1] ? ans : arr[i] - arr[i - 1];
  }
  return ans;
}
