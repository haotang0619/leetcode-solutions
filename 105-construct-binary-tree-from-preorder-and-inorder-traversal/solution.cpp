/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* traverse(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if(pl > pr) return nullptr;
        int root = preorder[pl];
        int imid = il;
        while(inorder[imid] != root) imid++;
        int len = imid - il;
        return new TreeNode(
            root,
            traverse(preorder, inorder, pl + 1, pl + len, il, imid - 1),
            traverse(preorder, inorder, pl + len + 1, pr, imid + 1, ir)
        );
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return traverse(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
