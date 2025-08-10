class Solution {
public:
    struct TrieNode {
        bool isEnd;
        map<char, TrieNode*> children;
        TrieNode() : isEnd(false), children({}) {}
    };

    void dfs(string& ans, string& now, TrieNode* node) {
        if(!node->isEnd) return;
        if(now.size() > ans.size()) ans = now;
        else if(now.size() == ans.size()) ans = min(ans, now);
        for(auto [c, next] : node->children) {
            now.push_back(c);
            dfs(ans, now, next);
            now.pop_back();
        }
    }

    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();
        root->isEnd = true;
        for(auto word : words) {
            TrieNode* node = root;
            for(auto c : word) {
                if(!node->children.contains(c)) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->isEnd = true;
        }
        string ans = "", now = "";
        dfs(ans, now, root);
        return ans;
    }
};
