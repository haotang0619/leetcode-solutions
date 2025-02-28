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
    void traversal(vector<pair<double, int>>& sums, int depth, TreeNode* node) {
        if(node == NULL) return;
        if(depth >= sums.size()) sums.push_back({0, 0});
        sums[depth].first += (double)(node->val);
        sums[depth].second++;
        traversal(sums, depth + 1, node->left);
        traversal(sums, depth + 1, node->right);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<double, int>> sums;
        traversal(sums, 0, root);
        vector<double> ans;
        for(auto x : sums) {
            ans.push_back((double)x.first / (double)x.second);
        }
        return ans;
    }
};
