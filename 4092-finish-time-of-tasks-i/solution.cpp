class Solution {
public:
    long long traverse(vector<vector<int>>& e, vector<int>& baseTime, int u) {
        if(e[u].size() == 0) return baseTime[u];
        long long minT = LLONG_MAX, maxT = LLONG_MIN;
        for(auto &v : e[u]) {
            long long t = traverse(e, baseTime, v);
            maxT = max(maxT, t), minT = min(minT, t);
        }
        return 2 * maxT - minT + baseTime[u];
    }

    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> e(n);
        for(auto &x : edges) e[x[0]].push_back(x[1]);
        return traverse(e, baseTime, 0);
    }
};
