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
    int minDepth(TreeNode* root, int depth = 1) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return depth;
        if(root->left == nullptr) return minDepth(root->right, depth + 1);
        if(root->right == nullptr) return minDepth(root->left, depth + 1);
        return min(minDepth(root->right, depth + 1), minDepth(root->left, depth + 1));
    }
};
