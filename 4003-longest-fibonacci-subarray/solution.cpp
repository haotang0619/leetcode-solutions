class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 2, now = 2, n = nums.size();
        for(int i = 2; i < n; i++) {
            if(nums[i] == nums[i - 1] + nums[i - 2]) {
                now++, ans = max(ans, now);
            } else now = 2;
        }
        return ans;
    }
};
