class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;
        while(i < j) {
            int m = (i + j) / 2;
            if(target == nums[m]) return m;
            if(nums[m] >= nums[0]) {
                if(target >= nums[0]) {
                    if(target > nums[m]) i = m + 1;
                    else j = m;
                } else i = m + 1;
            } else {
                if(target <= nums[n - 1]) {
                    if(target > nums[m]) i = m + 1;
                    else j = m;
                } else j = m;
            }
        }
        return target == nums[i] ? i : -1;
    }
};
