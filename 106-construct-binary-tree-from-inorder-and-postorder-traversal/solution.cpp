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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int i1, int i2, int p1, int p2) {
        if(i1 > i2) return NULL;
        int rootVal = postorder[p2];
        TreeNode* root = new TreeNode();
        root->val = rootVal;
        int lz = 0;
        while(inorder[i1 + lz] != rootVal) lz++;
        root->left = build(inorder, postorder, i1, i1 + lz - 1, p1, p1 + lz - 1);
        root->right = build(inorder, postorder, i1 + lz + 1, i2, p1 + lz, p2 - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};
