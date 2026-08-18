class WordDictionary {
public:
    struct Node {
        bool end = false;
        Node* child[26];
        Node() {
            memset(child, 0, sizeof(child));
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(auto& c : word) {
            int idx = c - 'a';
            if(node->child[idx] == nullptr) node->child[idx] = new Node();
            node = node->child[idx];
        }
        node->end = true;
    }

    bool traverse(string& word, Node* node, int i) {
        if(node == nullptr) return false;
        if(i == word.size()) return node->end;
        if(word[i] != '.') {
            int idx = word[i] - 'a';
            return traverse(word, node->child[idx], i + 1);
        }
        for(int idx = 0; idx < 26; idx++) {
            bool result = traverse(word, node->child[idx], i + 1);
            if(result) return true;
        }
        return false;
    }
    
    bool search(string word) {
        return traverse(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
