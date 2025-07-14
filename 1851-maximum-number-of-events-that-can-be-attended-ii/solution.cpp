class Solution {
public:
    int binSearch(vector<vector<int>>& events, int n, int target) {
        int l = 0, r = n - 1, pos = -1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(events[m][1] <= target) {
                pos = m;
                l = m + 1;
            } else r = m - 1;
        }
        return pos;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](auto &i, auto &j){
            return i[1] == j[1] ? i[0] < j[0] : i[1] < j[1];
        });
        int n = events.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        for(int i = 0; i < n; i++) {
            int pos = binSearch(events, n, events[i][0] - 1);
            // cout << i << " " << pos << endl;
            for(int j = 0; j <= k; j++) {
                dp[i][j][0] = i > 0 ? max(dp[i - 1][j][0], dp[i - 1][j][1]) : 0;
                if(j > 0) {
                    dp[i][j][1] = events[i][2];
                    if(pos >= 0) {
                        dp[i][j][1] = max(dp[i][j][1], max(dp[pos][j - 1][0], dp[pos][j - 1][1]) + events[i][2]);
                    }
                }
                // cout << i << " " << j << " | " << dp[i][j][0] << " " << dp[i][j][1] << endl;
            }
            // cout << endl;
        }
        int ans = 0;
        for(auto x : dp[n - 1]) ans = max(x[0], x[1]);
        return ans;
    }
};
