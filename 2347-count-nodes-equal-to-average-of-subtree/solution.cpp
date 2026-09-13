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
    pair<int, int> findAns(int& ans, TreeNode* node) {
        if(node == nullptr) return {0, 0};
        auto [lSum, lCnt] = findAns(ans, node->left);
        auto [rSum, rCnt] = findAns(ans, node->right);
        int sum = node->val + lSum + rSum, cnt = 1 + lCnt + rCnt;
        if(sum / cnt == node->val) ++ans;
        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        findAns(ans, root);
        return ans;
    }
};
