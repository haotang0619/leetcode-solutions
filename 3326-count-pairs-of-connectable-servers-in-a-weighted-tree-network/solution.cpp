class Solution {
public:
    void findServers(int node, int prev, int now, int speed, vector<vector<pair<int, int>>>& e, int &cnt) {
        if(now % speed == 0) cnt++;
        for(auto x : e[node]) {
            auto [v, w] = x;
            if(v == prev) continue;
            findServers(v, node, now + w, speed, e, cnt);
        }
    }
    
    // Saw hints
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> e(n, vector<pair<int, int>>({}));
        for(auto x : edges) {
            int a = x[0], b = x[1], w = x[2];
            e[a].push_back({b, w});
            e[b].push_back({a, w});
        }
        
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            vector<int> sizes;
            int sum = 0;
            for(auto x : e[i]) {
                auto [v, w] = x;
                int cnt = 0;
                findServers(v, i, w, signalSpeed, e, cnt);
                sizes.push_back(cnt);
                sum += cnt;
            }

            int pairs = 0;
            // This formula was from the hint!
            for(int i = 0; i < sizes.size(); i++) {
                if(i >= 1) pairs += sum * sizes[i - 1];
                sum -= sizes[i];
            }
            ans[i] = pairs;
        }
        return ans;
    }
};
