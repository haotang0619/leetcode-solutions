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
    void deleteByCases(TreeNode* node, TreeNode* parent, bool isLeft, int key) {
        if(node == NULL) return;
        if(node->val == key) {
            if(node->left == NULL && node->right == NULL) {
                if(isLeft) parent->left = NULL;
                else parent->right = NULL;
            } else if(node->left == NULL) {
                if(isLeft) parent->left = node->right;
                else parent->right = node->right;
            } else if(node->right == NULL) {
                if(isLeft) parent->left = node->left;
                else parent->right = node->left;
            } else {
                TreeNode* now = node->right;
                while(now->left != NULL) now = now->left;
                node->val = now->val;
                deleteByCases(node->right, node, false, node->val);
            }
        } else if(node->val > key) deleteByCases(node->left, node, true, key);
        else deleteByCases(node->right, node, false, key);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* tmpRoot = new TreeNode(0, root, NULL);
        deleteByCases(root, tmpRoot, true, key);
        return tmpRoot->left;
    }
};
