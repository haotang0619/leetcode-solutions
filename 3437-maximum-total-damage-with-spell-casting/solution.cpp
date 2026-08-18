class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        vector<pair<int, int>> v;
        int cnt = 0, prev = -1;
        for(auto& p : power) {
            if(p != prev) {
                if(cnt > 0) v.push_back({prev, cnt});
                cnt = 0;
            }
            prev = p, cnt++;
        };
        if(cnt > 0) v.push_back({prev, cnt});

        long long ans = 0;
        vector<vector<long long>> dp(v.size(), vector<long long>(2, 0));
        for(int i = 0; i < v.size(); i++) {
            dp[i][0] = i > 0 ? max(dp[i - 1][0], dp[i - 1][1]) : 0;
            dp[i][1] = (long long)v[i].first * v[i].second;
            long long add = 0;
            int j = i - 1;
            while(j >= 0 && v[j].first >= v[i].first - 2) j--;
            if(j >= 0) add = max({add, dp[j][0], dp[j][1]});
            dp[i][1] += add;
            ans = max({ans, dp[i][0], dp[i][1]});
        }
        return ans;
    }
};
