class Solution {
public:
    vector<pair<long long, int>> traverse(vector<int>& group, vector<vector<int>>& e, long long& ans, int parent, int u, int layer) {
        vector<pair<long long, int>> mpTotal(21, {0, 0});
        vector<vector<pair<long long, int>>> mps;
        for(auto& v : e[u]) {
            if(v == parent) continue;
            mps.push_back(traverse(group, e, ans, u, v, layer + 1));
        }

        int n = mps.size();
        int gpu = group[u];
        for(int i = 0; i < n; i++) {
            auto& [l, cnt] = mps[i][gpu];
            if(l > 0) ans += l - (long long)layer * cnt;
        }
        vector<int> cntTotal(21, 0);
        for(int i = 0; i < n; i++) {
            for(int gp = 1; gp <= 20; gp++) cntTotal[gp] += mps[i][gp].second;
        }
        for(int i = 0; i < n; i++) {
            for(int gp = 1; gp <= 20; gp++) {
                auto& [l, cnt1] = mps[i][gp];
                int cnt2 = cntTotal[gp] - cnt1;
                if(l > 0) ans += (l - (long long)layer * cnt1) * cnt2;
            }
        }
        
        for(auto& mp : mps) {
            for(int gp = 1; gp <= 20; gp++) {
                mpTotal[gp].first += mp[gp].first;
                mpTotal[gp].second += mp[gp].second;
            }
        }
        mpTotal[gpu].first += layer, mpTotal[gpu].second++;
        return mpTotal;
    }
    
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<vector<int>> e(n);
        for(auto& x : edges) {
            e[x[0]].push_back(x[1]);
            e[x[1]].push_back(x[0]);
        }
        long long ans = 0;
        traverse(group, e, ans, -1, 0, 1);
        return ans;
    }
};
