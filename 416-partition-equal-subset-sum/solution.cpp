class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        for(auto x : nums) {
            for(int i = target; i >= 1; i--) {
                int last = i - x;
                if(last > 0 && dp[last]) dp[i] = true;
            }
            if(x <= target) dp[x] = true;
            else return false;
        }
        return dp[target];
    }
};
