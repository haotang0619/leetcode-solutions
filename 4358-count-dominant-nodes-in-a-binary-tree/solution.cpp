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
        if(node == nullptr) return 0;
        int lMax = traverse(ans, node->left);
        int rMax = traverse(ans, node->right);
        int childMax = max(lMax, rMax);
        if(node->val >= childMax) ans++;
        return max(node->val, childMax);
    }
    
    int countDominantNodes(TreeNode* root) {
        int ans = 0;
        traverse(ans, root);
        return ans;
    }
};
