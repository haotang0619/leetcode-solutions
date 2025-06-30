class Solution {
public:
    bool isValid(string a, string b) {
        if(a.size() != b.size()) return false;
        int cnt = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) cnt++;
            if(cnt > 1) return false;
        }
        return true;
    }

    void dfs(set<int> &seen, vector<vector<int>> &edges, vector<int> &topo, int node) {
        seen.insert(node);
        for (auto x : edges[node]) {
            if (seen.find(x) == seen.end()) dfs(seen, edges, topo, x);
        }
        topo.push_back(node);
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // Build graph
        int n = words.size();
        vector<vector<int>> v(n + 1, vector<int>({}));
        for(int i = 0; i < n; i++) v[groups[i]].push_back(i);
        vector<vector<int>> edges(n, vector<int>({}));
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                for(auto x : v[i]) {
                    for(auto y : v[j]) {
                        if(isValid(words[x], words[y])) {
                            if(x < y) edges[x].push_back(y);
                            else edges[y].push_back(x);
                        }
                    }
                }
            }
        }
        
        // Topo sort by DFS
        vector<int> topo;
        set<int> seen;
        for(int i = 0; i < n; i++) {
            if (seen.find(i) == seen.end()) dfs(seen, edges, topo, i);
        }
        reverse(topo.begin(), topo.end());

        // Find longest path (asked GPT)
        vector<int> dp(n, 0);
        vector<int> parents(n, -1);
        int max_len = 0, node = 0;
        for(auto x : topo) {
            for(auto y : edges[x]) {
                if(dp[y] < dp[x] + 1) {
                    dp[y] = dp[x] + 1;
                    parents[y] = x;
                    if(max_len < dp[y]) {
                        max_len = dp[y];
                        node = y;
                    }
                }
            }
        }
        vector<string> ans;
        while(node != -1) {
            ans.push_back(words[node]);
            node = parents[node];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
