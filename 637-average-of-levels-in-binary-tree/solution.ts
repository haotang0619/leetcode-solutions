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

function averageOfLevels(root: BTreeNode | null): number[] {
  const sumOfLevels: number[] = [];
  const cntOfLevels: number[] = [];

  const traversal = [{ node: root, level: 0 }];
  let idx = 0;
  while (!!traversal[idx]) {
    const { node, level } = traversal[idx];
    if (!sumOfLevels[level]) sumOfLevels[level] = 0;
    if (!cntOfLevels[level]) cntOfLevels[level] = 0;
    sumOfLevels[level] += node?.val ?? 0;
    cntOfLevels[level] += 1;

    if (!!node?.left) traversal.push({ node: node?.left, level: level + 1 });
    if (!!node?.right) traversal.push({ node: node?.right, level: level + 1 });
    idx++;
  }

  return sumOfLevels.map((s, i) => s / cntOfLevels[i]);
}
