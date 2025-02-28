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
class FindElements {
public:
    set<int> st;

    FindElements(TreeNode* root) {
        recoverTree(root, 0);
    }

    void recoverTree(TreeNode* node, int val) {
        if(node == NULL) return;
        (*node).val = val;
        st.insert(val);
        recoverTree((*node).left, val * 2 + 1);
        recoverTree((*node).right, val * 2 + 2);
    }
    
    bool find(int target) {
        return st.find(target) != st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
