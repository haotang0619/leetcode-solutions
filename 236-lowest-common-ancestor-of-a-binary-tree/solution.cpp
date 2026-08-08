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
    pair<bool, bool> traverse(TreeNode*& ans, TreeNode* node, TreeNode* p, TreeNode* q, int& maxLv, int lv) {
        if(node == nullptr) return {false, false};
        auto l = traverse(ans, node->left, p, q, maxLv, lv + 1);
        auto r = traverse(ans, node->right, p, q, maxLv, lv + 1);
        pair<bool, bool> res = {node == p, node == q};
        res.first = res.first || l.first || r.first;
        res.second = res.second || l.second || r.second;
        if(res.first && res.second && maxLv < lv) maxLv = lv, ans = node;
        return res;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        int maxLv = -1;
        traverse(ans, root, p, q, maxLv, 0);
        return ans;
    }
};
