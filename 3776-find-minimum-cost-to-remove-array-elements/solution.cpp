class Solution {
public:
    // Checked a Solution:
    int findAns(int keep, int idx, vector<int>& nums, vector<vector<int>>& dp) {
        if(idx == nums.size()) return nums[keep];
        if(idx == nums.size() - 1) return max(nums[keep], nums[idx]);
        if(dp[idx][keep] != -1) return dp[idx][keep];

        int v1 = max(nums[keep], nums[idx]) + findAns(idx + 1, idx + 2, nums, dp);
        int v2 = max(nums[idx], nums[idx + 1]) + findAns(keep, idx + 2, nums, dp);
        int v3 = max(nums[keep], nums[idx + 1]) + findAns(idx, idx + 2, nums, dp);
        return dp[idx][keep] = min({v1, v2, v3});
    }

    int minCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return findAns(0, 1, nums, dp);
    }
};
