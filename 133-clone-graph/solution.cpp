/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> mp;
        if(node == NULL) return NULL;
        Node* node1 = new Node(node->val, node->neighbors);
        stack<Node*> sk;
        sk.push(node1);
        mp[1] = node1;
        unordered_set<int> st;
        while(!sk.empty()) {
            Node* curr = sk.top();
            sk.pop();
            if(st.find(curr->val) != st.end()) continue;
            st.insert(curr->val);
            vector<Node*> _neighbors;
            for(auto x : curr->neighbors) {
                if(mp[x->val] != NULL) {
                    _neighbors.push_back(mp[x->val]);
                } else {
                    Node* next = new Node(x->val, x->neighbors);
                    _neighbors.push_back(next);
                    mp[x->val] = next;
                    sk.push(next);
                }
            }
            curr->neighbors = _neighbors;
        }
        return node1;
    }
};
