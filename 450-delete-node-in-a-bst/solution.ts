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

function deleteNode(root: TreeNode | null, key: number): TreeNode | null {
    let tempRoot = new TreeNode(0, root, null);
    
    let parent = tempRoot;
    let direction = 'left';
    let deleted = root;
    while(!!deleted && deleted.val !== key) {
        parent = deleted;
        if(key < deleted.val) { deleted = deleted.left; direction = 'left'; }
        else { deleted = deleted.right; direction = 'right'; }
    }
    if(!deleted) return root;
    
    if(!deleted.left && !deleted.right) parent[direction] = null;
    else if(!deleted.left || !deleted.right) {
        parent[direction] = deleted.left || deleted.right;
    }else {
        let minimum = deleted.right;
        while(minimum.left) minimum = minimum.left;
        const val = minimum.val
        deleteNode(root, val);
        deleted.val = val;
    }
       
    return tempRoot.left;
};
