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
    void traverse(vector<int>& sum, TreeNode* node, int lv) {
        if(node == NULL) return;
        if(sum.size() <= lv) sum.push_back(0);
        sum[lv] += node->val;
        traverse(sum, node->left, lv + 1);
        traverse(sum, node->right, lv + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        vector<int> sum;
        traverse(sum, root, 0);
        return sum[sum.size() - 1];
    }
};
