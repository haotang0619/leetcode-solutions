class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if(nums[0] <= nums[size - 1]) return nums[0];
        int left = 0, right = size - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] > nums[mid + 1]) return nums[mid + 1];
            else if (nums[mid] > nums[0]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
};
