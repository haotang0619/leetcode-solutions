class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> e(n);
        for(auto& x : edges) e[x[0]].push_back(x[1]), e[x[1]].push_back(x[0]);
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            queue<tuple<int, int, int>> qu; // [u, parent, d]
            qu.push({i, -1, 0});
            int cnt = 0;
            while(!qu.empty() && cnt <= n * 2) {
                auto [u, parent, d] = qu.front();
                cnt++;
                qu.pop();
                for(auto& v : e[u]) {
                    if(v == parent) continue;
                    if(v == i) {
                        ans = min(ans, d + 1);
                        break;
                    }
                    qu.push({v, u, d + 1});
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
