class Solution {
public:
    // Saw topics, and Googled for struct
    struct TrieNode {
        int cnt;
        vector<int> pos;
        map<char, TrieNode*> children;
        TrieNode() : cnt(0), pos({}), children({}) {}
    };

    void dfs(TrieNode* node, vector<int> &ans, int sum) {
        int newSum = sum + node->cnt;
        for(auto x : node->pos) ans[x] = newSum;
        for(auto [c, child]: node->children) dfs(child, ans, newSum);
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        int idx = 0;
        for(auto s : words) {
            TrieNode* node = root;
            for(auto c : s) {
                if(node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
                node->cnt++;
            }
            node->pos.push_back(idx++);
        }
        vector<int> ans(words.size(), 0);
        dfs(root, ans, 0);
        return ans;
    }
};
