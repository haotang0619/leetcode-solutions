class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size(), minNow = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] <= minNow) minNow = nums[i];
            else {
                int added = ceil((double)nums[i] / minNow) - 1;
                ans += added;
                if(nums[i] % minNow > 0) minNow = nums[i] / (added + 1);
            }
        }
        return ans;
    }
};
