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
    void traverse1st(long long& sum, TreeNode* node) {
        if(node == nullptr) return;
        sum += node->val;
        traverse1st(sum, node->left);
        traverse1st(sum, node->right);
    }

    long long traverse2nd(long long& ans, long long& sum, TreeNode* node) {
        if(node == nullptr) return 0;
        long long lSum = traverse2nd(ans, sum, node->left);
        long long rSum = traverse2nd(ans, sum, node->right);
        ans = max(ans, (sum - lSum) * lSum);
        ans = max(ans, (sum - rSum) * rSum);
        return node->val + lSum + rSum;
    }

    int maxProduct(TreeNode* root) {
        long long ans = 0, sum = 0;
        traverse1st(sum, root);
        traverse2nd(ans, sum, root);
        return ans % (long long)(1e9 + 7);
    }
};
