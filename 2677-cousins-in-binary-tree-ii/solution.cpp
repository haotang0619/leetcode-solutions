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
    void traversal1(TreeNode* node, int lv, vector<int>& sum) {
        if(node == NULL) return;
        if(sum.size() <= lv) sum.push_back(0);
        sum[lv] += node->val;
        traversal1(node->left, lv + 1, sum);
        traversal1(node->right, lv + 1, sum);
    }

    void traversal2(TreeNode* node, int lv, vector<int>& sum, int sib) {
        if(node == NULL) return;
        node->val = sum[lv] - node->val - sib;
        int lval = node->left == NULL ? 0 : node->left->val;
        int rval = node->right == NULL ? 0 : node->right->val;
        traversal2(node->left, lv + 1, sum, rval);
        traversal2(node->right, lv + 1, sum, lval);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> sum;
        traversal1(root, 0, sum);
        traversal2(root, 0, sum, 0);
        return root;
    }
};
