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

type Traverse = { node: TreeNode; length: number; direction: 'L' | 'R' | null };

function longestZigZag(root: TreeNode | null): number {
  if (!root) return 0;
  let answer = 0;
  const traversal: Traverse[] = [{ node: root, length: 0, direction: null }];
  while (traversal[0]) {
    const { node, length, direction } = traversal.shift() as Traverse;
    answer = answer > length ? answer : length;
    if (node.left) {
      traversal.push({
        node: node.left,
        length: direction === 'L' ? 1 : length + 1,
        direction: 'L',
      });
    }
    if (node.right) {
      traversal.push({
        node: node.right,
        length: direction === 'R' ? 1 : length + 1,
        direction: 'R',
      });
    }
  }
  return answer;
}
