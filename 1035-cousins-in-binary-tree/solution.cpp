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
    void traversal(TreeNode* node, bool& ans, vector<set<int>>& v, int lv, int sib, int x, int y) {
        if(node == NULL || ans) return;
        if(v.size() <= lv) v.push_back(set<int>({}));
        if(node->val == x && sib != y && v[lv].find(y) != v[lv].end()
        || node->val == y && sib != x && v[lv].find(x) != v[lv].end()) {
            ans = true;
            return;
        }

        v[lv].insert(node->val);
        int lval = node->left == NULL ? -1 : node->left->val;
        int rval = node->right == NULL ? -1 : node->right->val;
        traversal(node->left, ans, v, lv + 1, rval, x, y);
        traversal(node->right, ans, v, lv + 1, lval, x, y);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        bool ans;
        vector<set<int>> v;
        traversal(root, ans, v, 0, -1, x, y);
        return ans;
    }
};
