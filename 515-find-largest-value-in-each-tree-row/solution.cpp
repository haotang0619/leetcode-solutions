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
    void solve(vector<int> &ans, TreeNode* node, int lv) {
        if(node == nullptr) return;
        if(ans.size() <= lv) ans.push_back(node->val);
        ans[lv] = max(ans[lv], node->val);
        solve(ans, node->left, lv + 1);
        solve(ans, node->right, lv + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        solve(ans, root, 0);
        return ans;
    }
};
