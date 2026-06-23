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
    int traverse(int &ans, TreeNode* node) {
        int nodeCnt = 1, returnCnt = 1;
        if(node->left != NULL) {
            int leftCnt = traverse(ans, node->left);
            nodeCnt = nodeCnt + leftCnt;
            returnCnt = max(returnCnt, 1 + leftCnt);
        }
        if(node->right != NULL) {
            int rightCnt = traverse(ans, node->right);
            nodeCnt = nodeCnt + rightCnt;
            returnCnt = max(returnCnt, 1 + rightCnt);
        }
        ans = max(ans, nodeCnt);
        return returnCnt;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 1;
        traverse(ans, root);
        return ans - 1;
    }
};
