class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> times(2 * n);
        for(int i = 0; i < n; i++) {
            times[i * 2] = startTime[i];
            times[i * 2 + 1] = endTime[i];
        }
        sort(times.begin(), times.end());
        int cnt = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < 2 * n; i++) {
            if(i == 0 || times[i] != times[i - 1]) mp[times[i]] = cnt++;
        }
        vector<int> dp(cnt, 0), indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int& a, int& b) {
            return endTime[a] < endTime[b];
        });
        int t = 1;
        for(auto& idx : indices) {
            while(t < mp[endTime[idx]]) {
                dp[t] = max(dp[t], dp[t - 1]);
                t++;
            }
            dp[t] = max(dp[t], dp[t - 1]);
            dp[t] = max(dp[t], dp[mp[startTime[idx]]] + profit[idx]);
        }
        return dp[t];
    }
};
