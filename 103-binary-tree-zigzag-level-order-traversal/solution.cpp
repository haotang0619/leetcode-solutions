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
    void traversal(vector<vector<int>>& ans, int depth, TreeNode* node) {
        if(node == NULL) return;
        if(depth >= ans.size()) ans.push_back({});
        ans[depth].push_back(node->val);
        traversal(ans, depth + 1, node->left);
        traversal(ans, depth + 1, node->right);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        traversal(ans, 0, root);
        for(int i = 0; i < ans.size(); i++) {
            if(i % 2 == 1) reverse(ans[i].begin(), ans[i].end());
        }
        return ans;        
    }
};
