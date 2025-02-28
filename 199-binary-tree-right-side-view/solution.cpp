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
    void traversal(vector<vector<int>>& vals, int depth, TreeNode* node) {
        if(node == NULL) return;
        if(depth >= vals.size()) vals.push_back({});
        vals[depth].push_back(node->val);
        traversal(vals, depth + 1, node->left);
        traversal(vals, depth + 1, node->right);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> vals;
        traversal(vals, 0, root);
        vector<int> ans;
        for(auto x : vals) ans.push_back(x[x.size() - 1]);
        return ans;        
    }
};
