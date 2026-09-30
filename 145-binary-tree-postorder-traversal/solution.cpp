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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        auto traverse = [&](auto&& self, TreeNode* node) {
            if(node == nullptr) return;
            self(self, node->left);
            self(self, node->right);
            ans.push_back(node->val);
        };
        traverse(traverse, root);
        return ans;
    }
};
