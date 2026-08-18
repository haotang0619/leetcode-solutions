class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, now = 0, prev = -1, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] > prev) now++, ans = max(ans, now);
            else now = 1;
            prev = nums[i];
        }
        now = 0, prev = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(nums[i] < prev) now++, ans = max(ans, now);
            else now = 1;
            prev = nums[i];
        }
        return ans;
    }
};
