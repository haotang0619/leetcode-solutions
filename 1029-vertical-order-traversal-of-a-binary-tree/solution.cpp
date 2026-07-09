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
    int shift = 999, size = 1999;
    void traverse(vector<vector<pair<int, int>>>& v, TreeNode* node, int idx, int lv) {
        if(node == nullptr) return;
        v[idx].push_back({lv, node->val});
        traverse(v, node->left, idx - 1, lv + 1);
        traverse(v, node->right, idx + 1, lv + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<pair<int, int>>> v(size);
        traverse(v, root, shift, 0);
        vector<vector<int>> ans;
        for(auto& x : v) {
            if(x.size() > 0) {
                sort(x.begin(), x.end());
                ans.push_back({});
                for(auto& [lv, val] : x) ans.back().push_back(val);
            }
        }
        return ans;
    }
};
