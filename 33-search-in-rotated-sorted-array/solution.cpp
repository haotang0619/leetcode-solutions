class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(target == nums[m]) return m;
            if(nums[m] >= nums[0]) {
                if(target >= nums[0]) {
                    if(target > nums[m]) l = m + 1;
                    else r = m;
                } else l = m + 1;
            } else {
                if(target <= nums[n - 1]) {
                    if(target > nums[m]) l = m + 1;
                    else r = m;
                } else r = m;
            }
        }
        return target == nums[l] ? l : -1;
    }
};
