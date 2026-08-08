class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            int prev = (m > 0) ? nums[m - 1] : INT_MIN;
            int next = (m < n - 1) ? nums[m + 1] : INT_MIN;
            if(prev < nums[m] && nums[m] > next) return m;
            if(prev > nums[m]) r = m;
            else l = m + 1;
        }
        return l;
    }
};
