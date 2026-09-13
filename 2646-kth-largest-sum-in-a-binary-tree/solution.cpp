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
    void traverse(vector<long long>& sum, TreeNode* node, int lv) {
        if(node == nullptr) return;
        if(sum.size() <= lv) sum.push_back(0);
        sum[lv] += node->val;
        traverse(sum, node->left, lv + 1);
        traverse(sum, node->right, lv + 1);
    }
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sum;
        traverse(sum, root, 0);
        if(sum.size() < k) return -1;
        sort(sum.rbegin(), sum.rend());
        return sum[k - 1];
    }
};
