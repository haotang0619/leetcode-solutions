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
    void traverse(vector<int>& v, TreeNode* node) {
        if(node == nullptr) return;
        traverse(v, node->left);
        v.push_back(node->val);
        traverse(v, node->right);
    }

    TreeNode* build(vector<int>& v, int l, int r) {
        if(l > r) return nullptr;
        int m = l + (r - l) / 2;
        return new TreeNode(v[m], build(v, l, m - 1), build(v, m + 1, r));
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        traverse(v, root);
        return build(v, 0, v.size() - 1);
    }
};
