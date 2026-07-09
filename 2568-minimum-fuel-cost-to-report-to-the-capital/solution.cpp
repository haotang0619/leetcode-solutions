class Solution {
public:
    pair<int, long long> traverse(vector<vector<int>>& e, int u, int parent, int seats) {
        long long ans = 0;
        int headCnt = 1;
        for(auto& v : e[u]) {
            if(v == parent) continue;
            auto [hcnt, fuel] = traverse(e, v, u, seats);
            headCnt += hcnt, ans += fuel;
        }
        if(u != 0) ans += ceil((double)headCnt / seats);
        return {headCnt, ans};
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> e(n);
        for(auto& x : roads) {
            e[x[0]].push_back(x[1]);
            e[x[1]].push_back(x[0]);
        }
        return traverse(e, 0, -1, seats).second;
    }
};
