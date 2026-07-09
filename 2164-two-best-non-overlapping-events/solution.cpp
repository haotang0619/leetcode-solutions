class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [](auto& a, auto& b) {
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        vector<vector<int>> dp(n, vector<int>(2, 0));
        for(int i = 0; i < n; i++) {
            dp[i][0] = max(i > 0 ? dp[i - 1][0] : 0, events[i][2]);
            if(i > 0) dp[i][1] = dp[i - 1][1];
            int idx = lower_bound(events.begin(), events.end(), events[i][0], [](auto& x, int val) {
                return x[1] < val;
            }) - events.begin() - 1;
            if(idx >= 0) dp[i][1] = max(dp[i][1], dp[idx][0] + events[i][2]);
        }
        return max(dp.back()[0], dp.back()[1]);
    }
};
