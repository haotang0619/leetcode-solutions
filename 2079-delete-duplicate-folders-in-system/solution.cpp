class Solution {
public:
    // Saw editorial, the key is *serialization*
    struct TrieNode {
        string serial;
        unordered_map<string, TrieNode*> children;
    };

    void serialize(TrieNode* node, map<string, int> &mp) {
        if(node->children.empty()) return;
        vector<string> v;
        for(auto [child, next] : node->children) {
            serialize(next, mp);
            v.push_back(child + "(" + next->serial + ")");
        }
        sort(v.begin(), v.end());
        for(auto s : v) node->serial += s;
        mp[node->serial]++;
    }

    void solve(vector<vector<string>> &ans, vector<string> &now, TrieNode* node, map<string, int> &mp) {
        if(mp[node->serial] > 1) return;
        if(!now.empty()) ans.push_back(now);
        for(auto [child, next] : node->children) {
            now.push_back(child);
            solve(ans, now, next, mp);
            now.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();
        for(auto path : paths) {
            TrieNode* node = root;
            for(auto p : path) {
                if(!node->children.count(p)) {
                    node->children[p] = new TrieNode();
                }
                node = node->children[p];
            }
        }
        
        map<string, int> mp;
        serialize(root, mp);
        
        vector<vector<string>> ans;
        vector<string> now;
        solve(ans, now, root, mp);
        return ans;
    }
};
