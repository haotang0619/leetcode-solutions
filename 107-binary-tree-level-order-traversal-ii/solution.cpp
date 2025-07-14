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
    void traversal(TreeNode* node, vector<vector<int>> &v, int lv) {
        if(node == nullptr) return;
        if(v.size() <= lv) v.push_back({});
        v[lv].push_back(node->val);
        traversal(node->left, v, lv + 1);
        traversal(node->right, v, lv + 1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        traversal(root, v, 0);
        reverse(v.begin(), v.end());
        return v;
    }
};
