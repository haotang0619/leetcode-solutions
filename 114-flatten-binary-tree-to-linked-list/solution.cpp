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
    void traversal(TreeNode* node, vector<TreeNode*>& nodes) {
        if(node == NULL) return;
        nodes.push_back(node);
        traversal(node->left, nodes);
        traversal(node->right, nodes);
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes;
        traversal(root, nodes);
        TreeNode* node = root;
        for(int i = 1; i < nodes.size(); i++) {
            node->left = NULL;
            node->right = nodes[i];
            node = nodes[i];
        }
    }
};
