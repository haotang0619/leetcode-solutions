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
class BSTIterator {
public:
    struct Node {
        TreeNode* treeNode;
        bool doneRight = false;
        Node* parent;
        Node(TreeNode* tr, Node* p) {
            treeNode = tr, parent = p;
        }
    };

    Node* it; 

    BSTIterator(TreeNode* root) {
        TreeNode* now = root;
        Node* parent = nullptr;
        while(now != nullptr) {
            it = new Node(now, parent);
            now = now->left;
            parent = it;
        }
    }
    
    int next() {
        int val = it->treeNode->val;
        if(it->treeNode->right == nullptr) it->doneRight = true;
        if(it->doneRight) {
            while(it != nullptr && it->doneRight) {
                Node* parent = it->parent;
                delete it;
                it = parent;
            }
        } else {
            it->doneRight = true;
            TreeNode* now = it->treeNode->right;
            Node* parent = it;
            while(now != nullptr) {
                it = new Node(now, parent);
                now = now->left;
                parent = it;
            }
        }
        return val;
    }
    
    bool hasNext() {
        return it != nullptr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
