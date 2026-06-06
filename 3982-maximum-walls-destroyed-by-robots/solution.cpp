class Solution {
public:
    // Saw all hints
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<int> indices(n, 0);
        for(int i = 0; i < n; i++) indices[i] = i;
        sort(indices.begin(), indices.end(), [&](auto a, auto b) {
            return robots[a] < robots[b];
        });
        sort(walls.begin(), walls.end());
        vector<vector<int>> dp(n, vector<int>(2, 0));
        for(int i = 0; i < n; i++) {
            int idx = indices[i];
            int prevIdx = i > 0 ? indices[i - 1] : -1;
            int nextIdx = i < n - 1 ? indices[i + 1] : -1;
            // Shoot left
            int l1 = robots[idx] - distance[idx], r = robots[idx];
            int l2 = l1;
            if(i > 0) {
                l1 = max(l1, robots[prevIdx] + 1);
                // If previous robot shoot right
                int prevR = min(robots[prevIdx] + distance[prevIdx], r - 1);
                l2 = max(l2, prevR + 1);
            }
            int wl1 = lower_bound(walls.begin(), walls.end(), l1) - walls.begin();
            int wl2 = lower_bound(walls.begin(), walls.end(), l2) - walls.begin();
            int wr = upper_bound(walls.begin(), walls.end(), r) - walls.begin();
            if(i == 0) dp[i][0] = wr - wl1;
            else dp[i][0] = max(dp[i - 1][0] + wr - wl1, dp[i - 1][1] + wr - wl2);
            
            // Shoot right
            int l = robots[idx];
            r = robots[idx] + distance[idx];
            if(i < n - 1) r = min(r, robots[nextIdx] - 1);
            int wl = lower_bound(walls.begin(), walls.end(), l) - walls.begin();
            wr = upper_bound(walls.begin(), walls.end(), r) - walls.begin();
            if(i == 0) dp[i][1] = wr - wl;
            else dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + wr - wl;
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
