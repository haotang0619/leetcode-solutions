class Solution {
public:
    // 1. Asked GPT for the deque logic
    // 2. Saw a solution
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        vector<long long> pSum(n, 0);
        for(int i = 0; i < n; i++) pSum[i] = nums[i] + (i > 0 ? pSum[i - 1] : 0);
        
        long long ans = LLONG_MIN;
        vector<vector<long long>> dp(m + 1, vector<long long>(n, LLONG_MIN));
        for(int i = 0; i < n; i++) dp[0][i] = 0;
        dp[1][l - 1] = pSum[l - 1];
        ans = max(ans, dp[1][l - 1]);
        
        for (int i = 1; i <= m; i++) {
            deque<vector<long long>> dq; // [pSum[index], index]
            dq.push_back({0, -1});
            
            for(int j = l; j < n; j++) {
                dp[i][j] = dp[i][j - 1];
                if(dp[i - 1][j - l] != LLONG_MIN) {
                    long long val = -pSum[j - l] + dp[i - 1][j - l];
                    while(dq.size() && dq.back()[0] <= val) dq.pop_back();
                    dq.push_back({val, j - l + 1});

                    while(!dq.empty()) {
                        int idx = dq.front()[1];
                        if(j >= r && idx <= j - r) dq.pop_front();
                        else break;
                    }
                    if(!dq.empty()) {
                        dp[i][j] = max(dp[i][j], pSum[j] + dq.front()[0]);
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
