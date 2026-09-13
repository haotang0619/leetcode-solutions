class Solution {
public:
    pair<int, int> traverse1st(vector<vector<pair<int, int>>>& dp, vector<vector<int>>& e, int parent, int u) {
        pair<int, int> res = {1, 0};
        auto& [even, odd] = res;
        for(int i = 0; i < e[u].size(); i++) {
            int v = e[u][i];
            if(v == parent) {
                dp[u].push_back({1, 0});
                continue;
            }
            auto childRes = traverse1st(dp, e, u, v);
            auto [childEven, childOdd] = childRes;
            even += childOdd, odd += childEven;
            dp[u].push_back(childRes);
        }
        return res;
    }

    void traverse2nd(vector<vector<pair<int, int>>>& dp, vector<pair<int, int>>& cnts, vector<vector<int>>& e, int parent, int u) {
        cnts[u] = {1, 0};
        auto& [even, odd] = cnts[u];
        if(parent != -1) {
            int idx = 0;
            while(e[u][idx] != parent) idx++;
            auto& [even1, odd1] = dp[u][idx];
            for(int i = 0; i < dp[parent].size(); i++) {
                int x = e[parent][i];
                if(x == u) continue;
                auto& info = dp[parent][i];
                even1 += info.second, odd1 += info.first;
            }
        }
        for(int i = 0; i < e[u].size(); i++) {
            int v = e[u][i];
            even += dp[u][i].second, odd += dp[u][i].first;
            if(v == parent) continue;
            traverse2nd(dp, cnts, e, u, v);
        }
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> e1(n), e2(m);
        for(auto& x : edges1) e1[x[0]].push_back(x[1]), e1[x[1]].push_back(x[0]);
        for(auto& x : edges2) e2[x[0]].push_back(x[1]), e2[x[1]].push_back(x[0]);
        vector<vector<pair<int, int>>> dp1(n), dp2(m);
        traverse1st(dp1, e1, -1, 0);
        traverse1st(dp2, e2, -1, 0);
        vector<pair<int, int>> cnts1(n), cnts2(m);
        traverse2nd(dp1, cnts1, e1, -1, 0);
        traverse2nd(dp2, cnts2, e2, -1, 0);
        int mxOddCnt = 0;
        for(auto& [even, odd] : cnts2) mxOddCnt = max(mxOddCnt, odd);
        vector<int> ans(n);
        for(int i = 0; i < n; i++) ans[i] = cnts1[i].first + mxOddCnt;
        return ans;
    }
};
