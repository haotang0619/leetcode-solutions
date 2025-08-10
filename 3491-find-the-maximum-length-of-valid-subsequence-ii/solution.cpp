class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i < k; i++) {
            vector<int> dp(k, 0);
            for(auto x : nums){
                int remain = x % k;
                int target = (i + k - remain) % k;
                dp[remain] = dp[target] + 1;
                ans = max(ans, dp[remain]);
            }
        }
        return ans;
    }
};
