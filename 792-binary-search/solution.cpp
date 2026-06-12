class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(nums[m] >= target) r = m;
            else l = m + 1;
        }
        return nums[l] == target ? l : -1;
    }
};
