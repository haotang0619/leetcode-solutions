/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        vector<Node*> v;
        Node* now = head;
        while(now != NULL) {
            v.push_back(now);
            now = now->next;
        }
        vector<int> r(v.size(), -1);
        for(int i = 0; i < v.size(); i++) {
            Node* rand = v[i]->random;
            if(rand != NULL) {
                for(int j = 0; j < v.size(); j++) {
                    if(v[j] == rand) {
                        r[i] = j;
                        break;
                    }
                }
            }
        }
        Node* newHead = new Node(head->val);
        now = newHead;
        v[0] = newHead;
        for(int i = 1; i < v.size(); i++) {
            now->next = new Node(v[i]->val);
            now = now->next;
            v[i] = now;
        }
        for(int i = 0; i < r.size(); i++) {
            if(r[i] > -1) v[i]->random = v[r[i]];
        }
        return newHead;
    }
};
