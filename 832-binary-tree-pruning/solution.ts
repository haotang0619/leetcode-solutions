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

function hasOne(node: BTreeNode | null): boolean {
  if (!node) return false;
  if (node.val === 1) return true;
  return hasOne(node.left) || hasOne(node.right);
}

function traverse(node: BTreeNode | null): BTreeNode | null {
  if (!node) return null;
  if (!hasOne(node)) return null;

  if (!hasOne(node.left)) node.left = null;
  else node.left = traverse(node.left);

  if (!hasOne(node.right)) node.right = null;
  else node.right = traverse(node.right);

  return node;
}

function pruneTree(root: TreeNode | null): TreeNode | null {
  return traverse(root);
}
