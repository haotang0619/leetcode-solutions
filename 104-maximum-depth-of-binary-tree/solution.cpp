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
    void traversal(int& ans, int curr, TreeNode* node) {
        if(node == NULL) return;
        ans = max(ans, curr);
        traversal(ans, curr + 1, node->left);
        traversal(ans, curr + 1, node->right);
    }

    int maxDepth(TreeNode* root) {
        int ans = 0;
        traversal(ans, 1, root);
        return ans;
    }
};
