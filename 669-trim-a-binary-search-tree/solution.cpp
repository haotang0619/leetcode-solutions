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
    void traverse(TreeNode* node, TreeNode* parent, int low, int high) {
        if(node == NULL) return;
        if(node->val < low) {
            if(parent->val == -1) parent->right = node->right;
            else parent->left = node->right;
            traverse(node->right, parent, low, high);
        } else if(node->val > high) {
            parent->right = node->left;
            traverse(node->left, parent, low, high);
        } else {
            traverse(node->left, node, low, high);
            traverse(node->right, node, low, high);
        }
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* tmp = new TreeNode(-1, NULL, root);
        traverse(root, tmp, low, high);
        return tmp->right;
    }
};
