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
    void traversal(vector<int>& infix, TreeNode* node) {
        if(node == NULL) return;
        traversal(infix, node->left);
        infix.push_back(node->val);
        traversal(infix, node->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> infix;
        traversal(infix, root);
        return infix[k - 1];
    }
};
