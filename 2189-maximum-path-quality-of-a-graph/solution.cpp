class Solution {
public:
    void findAns(vector<int>& values, vector<vector<pair<int, int>>>& e, unordered_map<int, int>& mp, int &ans, int maxTime, int t, int v, int node) {
        if(node == 0 && t > 0) ans = max(ans, v);
        for(auto [next, ti] : e[node]) {
            if(t + ti <= maxTime) {
                int newV = v;
                if(mp[next] == 0) newV += values[next];
                mp[next]++;
                findAns(values, e, mp, ans, maxTime, t + ti, newV, next);
                mp[next]--;
            }
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int ans = values[0], n = values.size();
        vector<vector<pair<int, int>>> e(n, vector<pair<int, int>>({}));
        for(auto &x : edges) {
            e[x[0]].push_back({x[1], x[2]});
            e[x[1]].push_back({x[0], x[2]});
        }
        unordered_map<int, int> mp;
        mp[0]++;
        findAns(values, e, mp, ans, maxTime, 0, values[0], 0);
        return ans;
    }
};
