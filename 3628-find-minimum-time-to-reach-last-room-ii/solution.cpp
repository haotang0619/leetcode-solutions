class Solution {
public:
    int MAX_TIME = 2e9;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dij(n, vector<int>(m, MAX_TIME));
        dij[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 1, 0, 0});
        vector<vector<bool>> v(n, vector<bool>(m, false));
        while(!pq.empty()) {
            auto top = pq.top();
            int time = top[0], step = top[1], x = top[2], y = top[3];
            pq.pop();
            
            if(v[x][y]) continue;
            dij[x][y] = time;
            int next_step = 3 - step;
            
            int i = x - 1, j = y;
            int next_time = i >= 0 ? max(time, moveTime[i][j]) + step : MAX_TIME;
            if(i >= 0 && !v[i][j] && dij[i][j] > next_time) {
                pq.push({next_time, next_step, i, j});
                dij[i][j] = next_time;
            }
            i = x + 1;
            next_time = i < n ? max(time, moveTime[i][j]) + step : MAX_TIME;
            if(i < n && !v[i][j] && dij[i][j] > next_time) {
                pq.push({next_time, next_step, i, j});
                dij[i][j] = next_time;
            }
            i = x, j = y - 1;
            next_time = j >= 0 ? max(time, moveTime[i][j]) + step : MAX_TIME;
            if(j >= 0 && !v[i][j] && dij[i][j] > next_time) {
                pq.push({next_time, next_step, i, j});
                dij[i][j] = next_time;
            }
            j = y + 1;
            next_time = j < m ? max(time, moveTime[i][j]) + step : MAX_TIME;
            if(j < m && !v[i][j] && dij[i][j] > next_time) {
                pq.push({next_time, next_step, i, j});
                dij[i][j] = next_time;
            }
            v[x][y] = true;
        }
        return dij[n - 1][m - 1];
    }
};
