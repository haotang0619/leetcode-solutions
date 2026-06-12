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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> mp;
        map<int, bool> isRoot;
        for(auto &x : descriptions) {
            int parent = x[0], child = x[1], isLeft = x[2];
            if(!mp.contains(parent)) mp[parent] = new TreeNode(parent);
            if(!mp.contains(child)) mp[child] = new TreeNode(child);
            if(isLeft) mp[parent]->left = mp[child];
            else mp[parent]->right = mp[child];

            isRoot[child] = false;
            if(!isRoot.contains(parent)) isRoot[parent] = true;
        }
        int rootNum = -1;
        for(auto &x : isRoot) rootNum = x.second ? x.first : rootNum;
        return mp[rootNum];
    }
};
