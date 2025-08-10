class Solution {
public:
    // odd => odd => odd => odd
    // odd => even => odd => even
    // even => odd => even => odd
    // even => even => even => even
    int maximumLength(vector<int>& nums) {
        vector<int> dp(4, 0);
        int ans = 0;
        for(auto x : nums) {
            if(x % 2 == 1) {
                dp[0]++;
                if(dp[1] % 2 == 0) dp[1]++;
                if(dp[2] % 2 == 1) dp[2]++;
            } else {
                if(dp[1] % 2 == 1) dp[1]++;
                if(dp[2] % 2 == 0) dp[2]++;
                dp[3]++;
            }
            ans = max(max(dp[0], dp[1]), max(dp[2], dp[3]));
        }
        return ans;
    }
};
