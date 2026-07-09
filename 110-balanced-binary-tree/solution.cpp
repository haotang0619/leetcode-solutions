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
    int traverse(bool& ans, TreeNode* node, int lv) {
        if(!ans) return -1;
        if(node == nullptr) return lv;
        int lv1 = traverse(ans, node->left, lv + 1);
        int lv2 = traverse(ans, node->right, lv + 1);
        if(abs(lv1 - lv2) > 1) ans = false;
        return max(lv1, lv2);
    }

    bool isBalanced(TreeNode* root) {
        bool ans = true;
        traverse(ans, root, 0);
        return ans;
    }
};
