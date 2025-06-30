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
    void traversal(TreeNode* node, vector<int>& v) {
        if(node == NULL) return;
        traversal(node->left, v);
        v.push_back(node->val);
        traversal(node->right, v);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        traversal(root, v);
        return v;
    }
};
