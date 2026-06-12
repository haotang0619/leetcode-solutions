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
    void traversal(TreeNode* node, int lv, vector<int> &sum) {
        if(sum.size() <= lv) sum.push_back(0);
        sum[lv] += node->val;
        if(node->left != NULL) traversal(node->left, lv + 1, sum);
        if(node->right != NULL) traversal(node->right, lv + 1, sum);
    }
        
    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        traversal(root, 0, sum);
        int ans = 1, maxNow = sum[0];
        for(int i = 2; i <= sum.size(); i++) {
            if(maxNow < sum[i - 1]) {
                maxNow = sum[i - 1];
                ans = i;
            }
        }
        return ans;
    }
};
