class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(m % 2 == 0) {
                if(m == n - 1) return nums[m];
                if(nums[m] == nums[m + 1]) l = m + 1;
                else r = m;
            } else {
                if(m == 0) return nums[m];
                if(nums[m] == nums[m - 1]) l = m + 1;
                else r = m;
            }
        }
        return nums[l];
    }
};
