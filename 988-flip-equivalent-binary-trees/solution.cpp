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
    void traversal(TreeNode* node1, TreeNode* node2, bool& ans){
        if(!ans || node1 == NULL && node2 == NULL) return;
        if(node1 == NULL && node2 != NULL || node1 != NULL && node2 == NULL || node1->val != node2->val) {
            ans = false;
            return;
        }
        if(node1->left != NULL && node2->left != NULL && node1->left->val == node2->left->val || node1->left == NULL && node2->left == NULL) {
            traversal(node1->left, node2->left, ans);
            traversal(node1->right, node2->right, ans);
        } else if(node1->left != NULL && node2->right != NULL && node1->left->val == node2->right->val || node1->left == NULL && node2->right == NULL) {
            traversal(node1->left, node2->right, ans);
            traversal(node1->right, node2->left, ans);
        } else {
            ans = false;
            return;
        }
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        bool ans = true;
        traversal(root1, root2, ans);
        return ans;
    }
};
