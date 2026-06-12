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
    void buildTree(vector<TreeNode*> &ans, vector<bool> &tree) {
        vector<TreeNode*> tmp(tree.size(), NULL);
        for(int i = tree.size() - 1; i >= 0; i--) {
            TreeNode* node = new TreeNode();
            int child = i * 2 + 1;
            if(child < tree.size() && tree[child]) {
                node->left = tmp[child];
                node->right = tmp[child + 1];
            }
            tmp[i] = node;
        }
        ans.push_back(tmp[0]);
    }
    
    void fillTreeArr(vector<TreeNode*> &ans, vector<bool> &tree, int idx, int n) {
        if(n == 0) {
            buildTree(ans, tree);
            return;
        }
        if(idx >= tree.size()) return;
        int layer = floor(log2(idx + 1));
        if(layer <= 1) {
            tree[idx] = tree[idx + 1] = true;
            fillTreeArr(ans, tree, idx + 2, n - 2);
        } else {
            int parent = (idx - 1) / 2;
            fillTreeArr(ans, tree, idx + 2, n);
            if(tree[parent]) {
                tree[idx] = tree[idx + 1] = true;
                fillTreeArr(ans, tree, idx + 2, n - 2);
                tree[idx] = tree[idx + 1] = false;
            }
        }
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0) return {};
        int p = (n + 1) / 2;
        vector<bool> tree(pow(2, p), false);
        tree[0] = true;
        vector<TreeNode*> ans;
        fillTreeArr(ans, tree, 1, n - 1);
        return ans;
    }
};
