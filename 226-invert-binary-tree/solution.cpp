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
    void traversal(TreeNode* node) {
        if(node == NULL) return;
        TreeNode* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        traversal(node->left);
        traversal(node->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        traversal(root);
        return root;
    }
};
