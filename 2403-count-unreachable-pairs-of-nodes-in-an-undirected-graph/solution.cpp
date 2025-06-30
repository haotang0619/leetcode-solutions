class Solution {
public:
    void dfs(vector<vector<int>> &e, vector<bool> &seen, int node, int &size) {
        seen[node] = true;
        size++;
        for(auto x : e[node]) {
            if(!seen[x]) dfs(e, seen, x, size);
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> e(n, vector<int>({}));
        for(auto x : edges) {
            e[x[0]].push_back(x[1]);
            e[x[1]].push_back(x[0]);
        }
        vector<bool> seen(n, false);
        vector<int> sizes;
        for(int i = 0; i < n; i++) {
            if(seen[i]) continue;
            int size = 0;
            dfs(e, seen, i, size);
            sizes.push_back(size);
        }
        
        long long ans = 0;
        vector<long long> prefix_sum(sizes.size(), sizes[0]);
        for(int i = 1; i < sizes.size(); i++) {
            prefix_sum[i] = prefix_sum[i - 1] + sizes[i];
        }
        for(int i = 1; i < sizes.size(); i++) {
            ans += sizes[i - 1] * (prefix_sum[sizes.size() - 1] - prefix_sum[i - 1]);
        }
        return ans;
    }
};
