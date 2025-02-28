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
    vector<int> getNext(string t, int idx) {
        vector<int> v = {0, 0, idx};
        bool flag = false;
        string num = "";
        for(int i = idx; i <= t.length(); i++) {
            if(flag) {
                if(i == t.length() || t[i] == '-') {
                    v[1] = stoi(num);
                    v[2] = i;
                    break;
                } else num.push_back(t[i]);
            } else if (t[i] != '-') {
                flag = true;
                num.push_back(t[i]);
                v[0] = i - idx;
            }
        }
        return v;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        TreeNode* root;
        stack<pair<int, TreeNode*>> sk;
        int idx = 0;
        while(idx < traversal.length()) {
            vector<int> v = getNext(traversal, idx);
            idx = v[2];
            TreeNode* node = new TreeNode(v[1]);
            if(sk.empty()) root = node;
            else {
                while(sk.top().first != v[0] - 1) sk.pop();
                if((*sk.top().second).left == NULL) (*sk.top().second).left = node;
                else {
                    (*sk.top().second).right = node;
                    sk.pop();
                }
            }
            sk.push({v[0], node});
        }
        return root;
    }
};
