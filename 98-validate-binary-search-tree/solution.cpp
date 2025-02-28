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
    void traversal(bool& ans, TreeNode* node, long long minV, long long maxV) {
        if(node == NULL) return;
        if(!ans) return;
        if(node->left != NULL && node->left->val >= node->val) {
            ans = false;
            return;
        }
        if(node->right != NULL && node->right->val <= node->val) {
            ans = false;
            return;
        }
        if(node->val <= minV || node->val >= maxV) {
            ans = false;
            return;
        }
        traversal(ans, node->left, minV, node->val);
        traversal(ans, node->right, node->val, maxV);
    }

    bool isValidBST(TreeNode* root) {
        bool ans = true;
        traversal(ans, root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
        return ans;
    }
};
