class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 0;
        for(int i = -500; i <= 500; i++) {
            vector<int> dp(501, 0);
            for(auto x : nums) {
                int target = x - i;
                if(target >= 0 && target <= 500) {
                    dp[x] = dp[target] + 1;
                    ans = max(ans, dp[x]);
                } else dp[x] = 1;
            }
        }
        return ans;
    }
};
