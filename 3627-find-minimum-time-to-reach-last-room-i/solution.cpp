class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        
        vector<vector<int>> dijkstra(n, vector<int>(m, 2e9));
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        set<vector<int>> st;
        
        dijkstra[0][0] = 0;
        pq.push({0, {0, 0}});
        while(st.size() < n * m) {
            int dist = pq.top().first;
            int x = pq.top().second[0], y = pq.top().second[1];
            pq.pop();
            if(st.find({x, y}) != st.end()) continue;

            st.insert({x, y});
            if(x - 1 >= 0 && st.find({x - 1, y}) == st.end()) {
                int newVal = max(min(dijkstra[x - 1][y], dist + 1), moveTime[x - 1][y] + 1);
                if(newVal < dijkstra[x - 1][y]) {
                    pq.push({newVal, {x - 1, y}});
                    dijkstra[x - 1][y] = newVal;
                }
            }
            if(x + 1 < n && st.find({x + 1, y}) == st.end()) {
                int newVal = max(min(dijkstra[x + 1][y], dist + 1), moveTime[x + 1][y] + 1);
                if(newVal < dijkstra[x + 1][y]) {
                    pq.push({newVal, {x + 1, y}});
                    dijkstra[x + 1][y] = newVal;
                }
            }
            if(y - 1 >= 0 && st.find({x, y - 1}) == st.end()) {
                int newVal = max(min(dijkstra[x][y - 1], dist + 1), moveTime[x][y - 1] + 1);
                if(newVal < dijkstra[x][y - 1]) {
                    pq.push({newVal, {x, y - 1}});
                    dijkstra[x][y - 1] = newVal;
                }
            }
            if(y + 1 < m && st.find({x, y + 1}) == st.end()) {
                int newVal = max(min(dijkstra[x][y + 1], dist + 1), moveTime[x][y + 1] + 1);
                if(newVal < dijkstra[x][y + 1]) {
                    pq.push({newVal, {x, y + 1}});
                    dijkstra[x][y + 1] = newVal;
                }
            }
        }
        return dijkstra[n - 1][m - 1];
    }
};
