class Solution {
public:
    using ull = unsigned long long;
    ull base = 131;
    
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        if(source.size() != target.size()) return -1;
        int n = source.size();
        vector<ull> rh(n + 1, 0), pows(25, 1);
        for(int i = 1; i <= n; i++) {
            rh[i] = rh[i - 1] * base + (source[i - 1] - 'a' + 1);
        }
        for(int i = 1; i < 25; i++) pows[i] = pows[i - 1] * base;

        int last = n;
        for(int i = n - 1; i >= 0; i--) {
            if(source[i] == target[i]) last = i;
            else break;
        }
        
        int m = costs.size();
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(auto& c : rules[i][0]) {
                if(c == '*') cnt++;
            }
            costs[i] += cnt;
        }
        
        vector<pair<ull, vector<int>>> ruleRh(m);
        for(int i = 0; i < m; i++) {
            auto& rrh = ruleRh[i];
            ull val = 0;
            vector<int> subPos;
            int sz = rules[i][0].size();
            for(int j = sz - 1; j >= 0; j--) {
                auto& c = rules[i][0][j];
                if(c == '*') subPos.push_back(j);
                else val += pows[sz - j - 1] * (c - 'a' + 1);
            }
            rrh.first = val, rrh.second = subPos;
        }
        
        vector<vector<int>> replacePos(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int sz = rules[j][0].size();
                if(i + sz > n) continue;
                auto& [rh2, subPos] = ruleRh[j];
                ull rh1 = rh[i + sz] - rh[i] * pows[sz];
                for(auto& p : subPos) {
                    rh1 -= pows[sz - p - 1] * (source[i + p] - 'a' + 1);
                }
                if(rh1 != rh2) continue;
                string tmp = target.substr(i, sz);
                if(tmp != rules[j][1]) continue;
                replacePos[i].push_back(j);
            }
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[0] = 0;
        // [d, u]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            if(u >= last) return d;
            for(auto& v : replacePos[u]) {
                int sz = rules[v][0].size();
                if(u + sz > n) continue;
                int cost = costs[v];
                if(source.substr(u, sz) == rules[v][1]) cost = 0;
                if(dist[u + sz] <= d + cost) continue;
                dist[u + sz] = d + cost;
                pq.push({dist[u + sz], u + sz});
            }
        }
        return -1;
    }
};
