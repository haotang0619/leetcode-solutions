class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, INT_MAX);
        dp[0] = 0;
        unordered_set<int> st(days.begin(), days.end());
        for(int d = 1; d <= 365; d++) {
            if(!st.contains(d)) {
                dp[d] = dp[d - 1];
                continue;
            }
            int a = dp[d - 1] + costs[0];
            int b = dp[max(d - 7, 0)] + costs[1];
            int c = dp[max(d - 30, 0)] + costs[2];
            dp[d] = min(min(a, b), c);
        }
        return dp[365];
    }
};
