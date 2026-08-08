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
    
    void insert(string word) {
        Node* node = root;
        for(auto& c : word) {
            int idx = c - 'a';
            if(node->child[idx] == nullptr) node->child[idx] = new Node();
            node = node->child[idx];
        }
        node->end = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(auto& c : word) {
            int idx = c - 'a';
            if(node->child[idx] == nullptr) return false;
            node = node->child[idx];
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(auto& c : prefix) {
            int idx = c - 'a';
            if(node->child[idx] == nullptr) return false;
            node = node->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
