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
    void traversal(bool& ans, int t, int sum, TreeNode* node) {
        if(ans || node == NULL) return;
        sum += node->val;
        if(node->left == NULL && node->right == NULL) {
            ans = t == sum;
            return;
        }
        traversal(ans, t, sum, node->left);
        traversal(ans, t, sum, node->right);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        traversal(ans, targetSum, 0, root);
        return ans;
    }
};
