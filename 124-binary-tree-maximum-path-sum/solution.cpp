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
    struct ExtendNode {
        int leftSum = 0, rightSum = 0, val = 0;
        ExtendNode *left = nullptr;
        ExtendNode *right = nullptr;
        ExtendNode (int v) {
            val = v;
        }
    };

    int traverse1st(TreeNode* node, ExtendNode* parent, bool isLeft) {
        if(node == nullptr) return 0;
        ExtendNode* now = new ExtendNode(node->val);
        if(isLeft) parent->left = now;
        else parent->right = now;
        int sum = node->val;
        now->leftSum = traverse1st(node->left, now, true);
        now->rightSum = traverse1st(node->right, now, false);
        return max(sum, max(sum + now->leftSum, sum + now->rightSum));
    }

    void traverse2nd(ExtendNode* node, int& ans, int prevSum) {
        if(node == nullptr) return;
        ans = max(ans, node->val + prevSum);
        ans = max(ans, node->val + node->leftSum + prevSum);
        ans = max(ans, node->val + node->rightSum + prevSum);
        int newPrevSum = max(node->val + prevSum, 0);
        int newPrevSumLeft = max(node->val + node->leftSum, 0);
        int newPrevSumRight = max(node->val + node->rightSum, 0);
        traverse2nd(node->left, ans, max(newPrevSum, newPrevSumRight));
        traverse2nd(node->right, ans, max(newPrevSum, newPrevSumLeft));
    }

    int maxPathSum(TreeNode* root) {
        ExtendNode* tmp = new ExtendNode(0);
        traverse1st(root, tmp, true);
        int ans = INT_MIN;
        traverse2nd(tmp->left, ans, 0);
        return ans;
    }
};
