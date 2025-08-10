class Solution {
public:
    void dfs(int i, vector<bool>& seen, vector<vector<int>>& edges) {
        seen[i] = true;
        for(auto x : edges[i]) {
            if(seen[x]) continue;
            seen[x] = true;
            dfs(x, seen, edges);
        }
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<vector<int>> edges(n, vector<int>({}));
        for(auto &p : properties) sort(p.begin(), p.end());
        for(int i = 0; i < n - 1; i++) {
            unordered_set<int> st;
            for(auto x : properties[i]) st.insert(x);
            for(int j = i + 1; j < n; j++) {
                int cnt = 0, prev = -1;
                for(auto x : properties[j]) {
                    if(prev != x) cnt += st.contains(x);
                    prev = x;
                }
                if(cnt >= k) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        vector<bool> seen(n, false);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(seen[i]) continue;
            dfs(i, seen, edges);
            ans++;
        }
        return ans;
    }
};
