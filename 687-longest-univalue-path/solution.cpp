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
    int traverse(int& ans, TreeNode* node) {
        int len = 1, size = 1, sl = 0, sr = 0, val = node->val;
        if(node->left != NULL) {
            int vl = node->left->val;
            sl = traverse(ans, node->left);
            if(val == vl) {
                len += sl;
                size = max(size, 1 + sl);
            }
        }
        if(node->right != NULL) {
            int vr = node->right->val;
            int sr = traverse(ans, node->right);
            if(val == vr) {
                len += sr;
                size = max(size, 1 + sr);
            }
        }
        ans = max(ans, len);
        return size;
    }

    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        traverse(ans, root);
        return max(ans - 1, 0);
    }
};
