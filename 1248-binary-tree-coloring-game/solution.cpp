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
    void traverse(vector<int>& cnt, TreeNode* node, int x, int idx) {
        if(node->val != x) cnt[idx]++;
        int nextIdx = idx;
        if(node->left != NULL) {
            if(node->val == x) nextIdx = 1;
            traverse(cnt, node->left, x, nextIdx);
        }
        if(node->right != NULL) {
            if(node->val == x) nextIdx = 2;
            traverse(cnt, node->right, x, nextIdx);
        }
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        vector<int> cnt(3, 0);
        traverse(cnt, root, x, 0);
        return cnt[0] > n / 2 || cnt[1] > n / 2 || cnt[2] > n / 2;
    }
};
