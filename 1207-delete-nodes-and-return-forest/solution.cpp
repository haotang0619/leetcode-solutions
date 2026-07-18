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
    void traverse(vector<TreeNode*>& ans, TreeNode* node, unordered_set<int>& del, bool parentDeleted) {
        if(node == nullptr) return;
        TreeNode* lc = node->left;
        TreeNode* rc = node->right;
        if(lc != nullptr && del.contains(lc->val)) node->left = nullptr;
        if(rc != nullptr && del.contains(rc->val)) node->right = nullptr;
        if(del.contains(node->val)) {
            traverse(ans, lc, del, true);
            traverse(ans, rc, del, true);
        } else {
            if(parentDeleted) ans.push_back(node);
            traverse(ans, lc, del, false);
            traverse(ans, rc, del, false);
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> del(to_delete.begin(), to_delete.end());
        traverse(ans, root, del, true);
        return ans;
    }
};
