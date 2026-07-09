/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traverse(vector<vector<int>>& e, TreeNode* node, int parent) {
        int val = node->val;
        if(parent >= 0) e[val].push_back(parent);
        if(node->left != nullptr) {
            e[val].push_back(node->left->val);
            traverse(e, node->left, val);
        }
        if(node->right != nullptr) {
            e[val].push_back(node->right->val);
            traverse(e, node->right, val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>> e(501);
        traverse(e, root, -1);
        vector<int> vis(501, false);
        int start = target->val;
        vis[start] = true;
        queue<pair<int, int>> qu; // [node, distance]
        qu.push({start, 0});
        vector<int> ans;
        while(!qu.empty()) {
            auto [u, d] = qu.front();
            qu.pop();
            if(d == k) {
                ans.push_back(u);
                continue;
            }
            for(auto& v : e[u]) {
                if(vis[v]) continue;
                vis[v] = true;
                qu.push({v, d + 1});
            }
        }
        return ans;
    }
};
