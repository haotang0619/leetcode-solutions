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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int, int> mp;
        for(int i = 0; i < postorder.size(); i++) mp[postorder[i]] = i;
        
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> sk;
        sk.push(root);
        
        for(int i = 1; i < preorder.size(); i++) {
            int x = preorder[i];
            TreeNode* node = new TreeNode(x);
            while(mp[x] > mp[sk.top()->val]) sk.pop();
            if(sk.top()->left == NULL) sk.top()->left = node;
            else { 
                sk.top()->right = node; 
                sk.pop();
            }
            sk.push(node);
        }
        return root;
    }
};
