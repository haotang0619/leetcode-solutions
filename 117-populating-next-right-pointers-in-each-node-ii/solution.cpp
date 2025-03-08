/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void traversal(Node* node, int lv, vector<Node*>& nodes) {
        if(node == NULL) return;
        if(nodes.size() <= lv) nodes.push_back(node);
        else {
            nodes[lv]->next = node;
            nodes[lv] = node;
        }
        node->next = NULL;
        traversal(node->left, lv + 1, nodes);
        traversal(node->right, lv + 1, nodes);
    }

    Node* connect(Node* root) {
        vector<Node*> nodes;
        traversal(root, 0, nodes);
        return root;
    }
};
