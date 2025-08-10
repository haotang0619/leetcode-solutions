class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int reversed = -1, n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                if(reversed != -1) return false;
                reversed = i;
            }
        }
        if(reversed == -1 || reversed == 0 || reversed == n - 2) return true;
        return (nums[reversed - 1] <= nums[reversed + 1]) || (nums[reversed] <= nums[reversed + 2]);
    }
};
