class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int r = lower_bound(nums.begin(), nums.end(), 0) - nums.begin(), l = r - 1;
        int n = nums.size(), i = 0;
        vector<int> ans(n);
        while(l >= 0 && r < n) {
            if(abs(nums[l]) <= abs(nums[r])) ans[i++] = nums[l] * nums[l--];
            else ans[i++] = nums[r] * nums[r++];
        }
        while(l >= 0) ans[i++] = nums[l] * nums[l--];
        while(r < n) ans[i++] = nums[r] * nums[r++];
        return ans;
    }
};
