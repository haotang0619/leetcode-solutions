class Solution {
public:
    void dijkstra(vector<vector<long long>>& dist, vector<vector<int>>& mp, int idx) {
        dist[idx][idx] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, idx});
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[idx][u]) continue;
            for(int v = 0; v < 26; v++) {
                int d1 = mp[u][v];
                if(d1 == INT_MAX) continue;
                if(d + d1 >= dist[idx][v]) continue;
                dist[idx][v] = d + d1;
                pq.push({dist[idx][v], v});
            }
        }
    }

    long long minimumCost(string src, string tar, vector<char>& orig, vector<char>& chan, vector<int>& cost) {
        vector<vector<int>> mp(26, vector<int>(26, INT_MAX));
        int m = orig.size();
        for(int i = 0; i < m; i++) {
            mp[orig[i] - 'a'][chan[i] - 'a'] = min(mp[orig[i] - 'a'][chan[i] - 'a'], cost[i]);
        }
        vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));
        for(int u = 0; u < 26; u++) dijkstra(dist, mp, u);
        long long ans = 0;
        int n = src.size();
        for(int i = 0; i < n; i++) {
            long long d = dist[src[i] - 'a'][tar[i] - 'a'];
            if(d == LLONG_MAX) return -1;
            ans += d;
        }
        return ans;

    }
};
