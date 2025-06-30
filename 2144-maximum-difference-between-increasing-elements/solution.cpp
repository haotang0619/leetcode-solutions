class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_now = nums[0], ans = -1;
        for(int i = 1; i < nums.size(); i++) {
            int diff = nums[i] - min_now;
            if(diff > 0) ans = max(ans, diff);
            min_now = min(min_now, nums[i]);
        }
        return ans;
    }
};
