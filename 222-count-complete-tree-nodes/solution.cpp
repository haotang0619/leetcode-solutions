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
    int count(TreeNode* node, int& h, int d) {
        if(node == nullptr) return 0;
        if(h == d) return 1;
        int rCnt = count(node->right, h, d + 1);
        int maxCnt = pow(2, h - d) - 1;
        if(maxCnt == rCnt) return 1 + maxCnt * 2;
        int minCnt = pow(2, h - d - 1) - 1;
        if(minCnt < rCnt) return 1 + maxCnt + rCnt;
        return 1 + rCnt + count(node->left, h, d + 1);
    }

    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int h = 0;
        TreeNode* node = root;
        while(node != nullptr) h++, node = node->left;
        return count(root, h, 1);
    }
};
