class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> obstacles1;
        for(auto ob : obstacles) obstacles1.push_back({ob[1], ob[0]});
        sort(obstacles.begin(), obstacles.end());
        sort(obstacles1.begin(), obstacles1.end());
        int ans = 0, dir = 0, n = obstacles.size(), x = 0, y = 0;
        for(auto k : commands) {
            if(k == -2) dir = (dir + 1) % 4;
            else if(k == -1) dir = (dir + 3) % 4;
            else {
                int move = k;
                // North
                if(dir == 0) {
                    int idx = upper_bound(obstacles.begin(), obstacles.end(), vector<int>({x, y})) - obstacles.begin();
                    if(idx >= 0 && idx < n) {
                        int x1 = obstacles[idx][0], y1 = obstacles[idx][1];
                        if(x1 == x && y1 - y <= move) move = y1 - y - 1;
                    }
                    y += move;
                // West
                } else if(dir == 1) {
                    int idx = obstacles1.rend() - upper_bound(obstacles1.rbegin(), obstacles1.rend(), vector<int>({y, x}), greater<vector<int>>()) - 1;
                    if(idx >= 0 && idx < n) {
                        int y1 = obstacles1[idx][0], x1 = obstacles1[idx][1];
                        if(y1 == y && x - x1 <= move) move = x - x1 - 1;
                    }
                    x -= move;
                // South
                } else if(dir == 2) {
                    int idx = obstacles.rend() - upper_bound(obstacles.rbegin(), obstacles.rend(), vector<int>({x, y}), greater<vector<int>>()) - 1;
                    if(idx >= 0 && idx < n) {
                        int x1 = obstacles[idx][0], y1 = obstacles[idx][1];
                        if(x1 == x && y - y1 <= move) move = y - y1 - 1;
                    }
                    y -= move;
                // East
                } else {
                    int idx = upper_bound(obstacles1.begin(), obstacles1.end(), vector<int>({y, x})) - obstacles1.begin();
                    if(idx >= 0 && idx < n) {
                        int y1 = obstacles1[idx][0], x1 = obstacles1[idx][1];
                        if(y1 == y && x1 - x <= move) move = x1 - x - 1;
                    }
                    x += move;
                }
                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }
};
