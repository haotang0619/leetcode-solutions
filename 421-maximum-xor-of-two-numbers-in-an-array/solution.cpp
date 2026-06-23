class Trie {
public:
    struct Node {
        Node* child[2];
        Node() {
            memset(child, 0, sizeof(child));
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for(int i = 0; i < 32; i++) {
            int idx = (num >> (31 - i)) & 1;
            if(node->child[idx] == NULL) node->child[idx] = new Node();
            node = node->child[idx];
        }
    }

    void traverse(Node* node, int& num, int &ans, int& now, int idx) {
        if(idx == 32) {
            ans = max(ans, now);
            return;
        }
        int d = (num >> (31 - idx)) & 1;
        int d1 = d ^ 1;
        for(int i = 0; i < 2; i++) {
            int x = d1 == 0 ? i : 1 - i;
            if(node->child[x] == NULL) continue;
            int tmp = now;
            now |= ((d ^ x) << (31 - idx));
            traverse(node->child[x], num, ans, now, idx + 1);
            now = tmp;
            break;
        }
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie tr;
        int ans = 0, now = 0;
        for(auto &num : nums) {
            tr.traverse(tr.root, num, ans, now, 0);
            tr.insert(num);
        }
        return ans;
    }
};
