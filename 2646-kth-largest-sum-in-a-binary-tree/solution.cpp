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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sum;
        traversal(root, 0, sum);
        sort(sum.begin(), sum.end(), greater<long long>());
        return sum.size() >= k ? sum[k - 1] : -1;
    }

private:
    void traversal(TreeNode* node, int lv, vector<long long>& sum) {
        if(node == NULL) return;
        if(sum.size() <= lv) sum.push_back(0LL);
        sum[lv] += node->val;
        traversal(node->left, lv + 1, sum);
        traversal(node->right, lv + 1, sum);
    }
};
