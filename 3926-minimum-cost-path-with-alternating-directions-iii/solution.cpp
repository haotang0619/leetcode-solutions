class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 0}, {0, 1}, {1, 0}};
    
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        vector<vector<long long>> dist(m * n, vector<long long>(2, LLONG_MAX));
        dist[0][0] = 1;
        priority_queue<tuple<long long, int, bool>, vector<tuple<long long, int, bool>>, greater<>> pq; // [d, u, isEven]
        pq.push({1, 0, false});
        while(!pq.empty()) {
            auto [d, u, isEven] = pq.top();
            pq.pop();
            if(d > dist[u][isEven]) continue;
            if(u == m * n - 1) return d;
            int ui = u / n, uj = u % n;
            for(auto& [x, y] : dir) {
                int vi = ui + x, vj = uj + y, v = vi * n + vj;
                if(vi < 0 || vi >= m || vj < 0 || vj >= n) continue;
                int pen = penalty[ui][uj];
                long long d1 = d;
                if(x == 0 && y == 0) d1 += pen;
                else if(x < 0 || y < 0) {
                    d1 += (vi + 1) * (vj + 1);
                    if(!isEven) d1 += pen;
                } else {
                    d1 += (vi + 1) * (vj + 1);
                    if(isEven) d1 += pen;
                }
                
                if(d1 >= dist[v][!isEven]) continue;
                dist[v][!isEven] = d1;
                pq.push({d1, v, !isEven});
            }
        }
        return LLONG_MAX;
    }
};
