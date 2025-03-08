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
    void traversal(int& sum, int curr, TreeNode* node) {
        if(node == NULL) return;
        curr = curr * 10 + node->val;
        if(node->left == NULL && node->right == NULL) {
            sum += curr;
            return;
        }
        traversal(sum, curr, node->left);
        traversal(sum, curr, node->right);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        traversal(sum, 0, root);
        return sum;
    }
};
