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
    void traverse(vector<TreeNode*> &ans, TreeNode* node, unordered_set<int> &del, bool noParent) {
        bool beDeleted = del.contains(node->val);
        if(noParent && !beDeleted) ans.push_back(node);
        TreeNode* l = node->left;
        TreeNode* r = node->right;
        if(l != NULL) {
            if(del.contains(l->val)) node->left = NULL;
            traverse(ans, l, del, beDeleted);
        }
        if(r != NULL) {
            if(del.contains(r->val)) node->right = NULL;
            traverse(ans, r, del, beDeleted);
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> del;
        for(auto x : to_delete) del.insert(x);
        if(root == NULL) return ans;
        traverse(ans, root, del, true);
        return ans;
    }
};
