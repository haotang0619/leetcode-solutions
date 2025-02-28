class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int ans1 = -1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target && (mid == 0 || nums[mid - 1] != target)) {
                ans1 = mid;
                break;
            } else if(left == right) break;
            else if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }

        left = 0; right = n - 1;
        int ans2 = -1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target && (mid == n - 1 || nums[mid + 1] != target)) {
                ans2 = mid;
                break;
            } else if(left == right) break;
            else if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        return {ans1, ans2};
    }
};
