class Solution {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) {
            if(a[1] != b[1]) return a[1] < b[1];
            if(a[0] != b[0]) return a[0] < b[0];
            return a[2] < b[2];
        });
        vector<long long> dp(n, 0), mx(n, LLONG_MIN);
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            auto& x = meetings[i];
            int l = x[0], r = x[1], v = x[2];

            int l1 = 0, r1 = i - 1;
            while(l1 < r1) {
                int m = l1 + (r1 - l1) / 2;
                if(meetings[m][1] <= l) l1 = m + 1;
                else r1 = m;
            }

            int idx = l1;
            if(meetings[idx][1] > l) idx--;
            if(idx >= 0) dp[i] = mx[idx] + l + v;
            else dp[i] = v;
            mx[i] = max(i > 0 ? mx[i - 1] : LLONG_MIN, dp[i] - r);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
