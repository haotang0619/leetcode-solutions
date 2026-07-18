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
    void traverse(unordered_map<int, vector<int>>& mp, TreeNode* node, int parent) {
        int val = node->val;
        if(parent > -1) mp[val].push_back(parent);
        if(node->left != nullptr) {
            mp[val].push_back(node->left->val);
            traverse(mp, node->left, val);
        }
        if(node->right != nullptr) {
            mp[val].push_back(node->right->val);
            traverse(mp, node->right, val);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> mp;
        traverse(mp, root, -1);
        int ans = 0;
        queue<pair<int, int>> qu; // [u, d]
        qu.push({start, 0});
        unordered_set<int> vis;
        vis.insert(start);
        while(!qu.empty()) {
            auto [u, d] = qu.front();
            qu.pop();
            ans = max(ans, d);
            for(auto& v : mp[u]) {
                if(vis.contains(v)) continue;
                vis.insert(v);
                qu.push({v, d + 1});
            }
        }
        return ans;
    }
};
