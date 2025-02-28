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
    void traversal(bool& ans, TreeNode* n1, TreeNode* n2) {
        if(!ans) return;
        if(n1 == NULL && n2 == NULL) return;
        if(n1 == NULL && n2 != NULL || n1 != NULL && n2 == NULL || n1->val != n2->val) {
            ans = false;
            return;
        }
        traversal(ans, n1->left, n2->left);
        traversal(ans, n1->right, n2->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = true;
        traversal(ans, p, q);
        return ans;
    }
};
