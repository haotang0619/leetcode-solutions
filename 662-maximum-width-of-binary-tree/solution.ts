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

function traversal(node: BTreeNode | null, list: bigint[], idx: bigint): void {
  if (!node) return;
  list.push(idx);
  traversal(node.left, list, idx * BigInt(2) + BigInt(1));
  traversal(node.right, list, idx * BigInt(2) + BigInt(2));
}

function widthOfBinaryTree(root: BTreeNode | null): number {
  const list: bigint[] = [];
  traversal(root, list, BigInt(0));
  list.sort((a, b) => Number(a - b));

  const len = list.length;
  const levels: bigint[][] = [];
  let level = 0;
  let powerOfTwo = BigInt(2);

  for (let i = 0; i < len; i++) {
    while (list[i] > powerOfTwo - BigInt(2)) {
      level++;
      powerOfTwo *= BigInt(2);
    }
    if (!levels[level]) levels[level] = [list[i]];
    else levels[level][1] = list[i];
  }

  const answer = levels.reduce((ans, lv) => {
    const width = lv.length === 1 ? 1 : lv[1] - lv[0] + BigInt(1);
    return Math.max(ans, Number(width));
  }, 0);

  return answer;
}
