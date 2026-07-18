struct Node {
    bool end = false;
    Node* child[26];
    Node() {
        memset(child, 0, sizeof(child));
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string& word) {
        Node* node = root;
        for(auto& c : word) {
            int idx = c - 'a';
            if(node->child[idx] == nullptr) node->child[idx] = new Node();
            node = node->child[idx];
        }
        node->end = true;
    }

    void erase(string& word) {
        Node *node = root, *parent;
        for(auto& c : word) {
            int idx = c - 'a';
            if(node->child[idx] == nullptr) return;
            parent = node;
            node = node->child[idx];
        }
        bool hasChild = false;
        for(int i = 0; i < 26; i++) {
            if(node->child[i] != nullptr) {
                hasChild = true;
                break;
            }
        }
        if(hasChild) node->end = false;
        else {
            int idx = word.back() - 'a';
            parent->child[idx] = nullptr;
        }
    }
};

class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void traverse(vector<vector<char>>& board, vector<vector<bool>>& vis, vector<string>& ans, string& now, pair<int, int> u, Trie* tr, Node* node) {
        int m = board.size(), n = board[0].size();
        auto& [i, j] = u;
        
        int idx = board[i][j] - 'a';
        if(node->child[idx] == nullptr) return;
        node = node->child[idx];
        if(node->end) {
            ans.push_back(now);
            tr->erase(now);
        }
        
        for(auto& [x, y] : dir) {
            int i1 = i + x, j1 = j + y;
            if(i1 < 0 || i1 >= m || j1 < 0 || j1 >= n) continue;
            if(vis[i1][j1]) continue;
            vis[i1][j1] = true;
            now += board[i1][j1];
            traverse(board, vis, ans, now, {i1, j1}, tr, node);
            now.pop_back();
            vis[i1][j1] = false;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        Trie* tr = new Trie();
        for(auto& word : words) tr->insert(word);
        
        vector<string> ans;
        string now;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                Node* node = tr->root;
                vis[i][j] = true;
                now += board[i][j];
                traverse(board, vis, ans, now, {i, j}, tr, node);
                now.pop_back();
                vis[i][j] = false;
            }
        }
        return ans;
    }
};
