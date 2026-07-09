// Asked GPT for the node pool to prevent MLE
class Trie {
public:
    struct Node {
        int child[26];
        int ansIdx = -1;
        Node() {
            memset(child, -1, sizeof(child));
        }
    };

    Node* root;
    vector<Node> pool; // IMPORTANT
    int nodeIdx = 0;

    Trie(int maxLen = 0) {
        pool.resize(maxLen + 1);
        root = &pool[nodeIdx++];
    }

    void setMinChild(Node* node, string& s, vector<string>& wc, int& idx) {
        if(node->ansIdx == -1 || wc[node->ansIdx].size() > s.size()) {
            node->ansIdx = idx;
        }
    }

    void insert(string& s, vector<string>& wc, int& idx) {
        Node* now = root;
        int n = s.size();
        for(int i = n - 1; i >= 0; i--) {
            setMinChild(now, s, wc, idx);
            int idx = s[i] - 'a';
            if(now->child[idx] == -1) now->child[idx] = nodeIdx++;
            now = &pool[now->child[idx]];
        }
        setMinChild(now, s, wc, idx);
    }

    int findAns(string& s) {
        Node* now = root;
        int n = s.size();
        for(int i = n - 1; i >= 0; i--) {
            int idx = s[i] - 'a';
            if(now->child[idx] == -1) break;
            now = &pool[now->child[idx]];
        }
        return now->ansIdx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        int tot = 0, n1 = wc.size(), n2 = wq.size();
        for(int i = 0; i < n1; i++) tot += wc[i].size();
        Trie tr(tot);
        for(int i = 0; i < n1; i++) tr.insert(wc[i], wc, i);
        vector<int> ans(n2);
        for(int i = 0; i < n2; i++) ans[i] = tr.findAns(wq[i]);
        return ans;
    }
};
