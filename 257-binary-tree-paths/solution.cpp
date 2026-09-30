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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        auto traverse = [&](auto&& self, TreeNode* node, string s) {
            if(node == nullptr) return;
            s += to_string(node->val) + "->";
            if(node->left == nullptr && node->right == nullptr) {
                int n = s.size();
                if(n > 0) ans.push_back(s.substr(0, n - 2));
            }
            self(self, node->left, s);
            self(self, node->right, s);
        };
        traverse(traverse, root, "");
        return ans;
    }
};
