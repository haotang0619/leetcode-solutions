class Trie {
public:
    struct Node {
        bool end = false;
        Node* child[26];
        Node() {
            memset(child, 0, sizeof(child));
        }
    };
    
    Node* root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string s) {
        Node* now = root;
        for(auto c : s) {
            if(now->child[c - 'a'] == NULL) {
                now->child[c - 'a'] = new Node();
            }
            now = now->child[c - 'a'];
        }
        now->end = true;
    }
    
    bool lookup(string s) {
        Node* now = root;
        for(auto c : s) {
            if(now->end) return true;
            if(now->child[c - 'a'] == NULL) return false;
            now = now->child[c - 'a'];
        }
        return now->end;
    }
};

class StreamChecker {
public:
    Trie* t;
    string now;
    
    StreamChecker(vector<string>& words) {
        t = new Trie();
        for(auto &w : words) {
            reverse(w.begin(), w.end());
            t->insert(w);
        }
    }
    
    bool query(char letter) {
        now = letter + now;
        if(now.size() >= 300) now.pop_back();
        return t->lookup(now);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
