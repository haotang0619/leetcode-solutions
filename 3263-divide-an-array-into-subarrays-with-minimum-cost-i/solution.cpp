class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = INT_MAX, n = nums.size();
        for(int j = 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                ans = min(ans, nums[0] + nums[j] + nums[k]);
            }
        }
        return ans;
    }
};
