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
    // Asked GPT for memo
    unordered_map<TreeNode*, unordered_map<int, int>> memo;

    int minCameraCover(TreeNode* root, bool force = false, bool prev = false) {
        if(root == nullptr) return 0;
        if(memo.contains(root) && memo[root].contains(force * 2 + prev)) {
            return memo[root][force * 2 + prev];
        }

        int ans = INT_MAX;
        // This node is not monitored yet
        if(!prev) {
            // No camera here, force install at left child:
            if(!force && root->left != nullptr) {
                int leftAns = minCameraCover(root->left, true, false);
                int rightAns = minCameraCover(root->right, false, false);
                ans = min(ans, leftAns + rightAns);
            }
            // No camera here, force install at right child:
            if(!force && root->right != nullptr) {
                int leftAns = minCameraCover(root->left, false, false);
                int rightAns = minCameraCover(root->right, true, false);
                ans = min(ans, leftAns + rightAns);
            }
            // Put a camera here:
            int leftAns = minCameraCover(root->left, false, true);
            int rightAns = minCameraCover(root->right, false, true);
            ans = min(ans, 1 + leftAns + rightAns);
        // This node is already monitored
        } else {
            // No camera here:
            int leftAns = minCameraCover(root->left, false, false);
            int rightAns = minCameraCover(root->right, false, false);
            ans = min(ans, leftAns + rightAns);
            // Still put a camera here:
            leftAns = minCameraCover(root->left, false, true);
            rightAns = minCameraCover(root->right, false, true);
            ans = min(ans, 1 + leftAns + rightAns);
        }
        return memo[root][force * 2 + prev] = ans;
    }
};
