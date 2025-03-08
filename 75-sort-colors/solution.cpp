class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int idx1 = 0, idx2 = n - 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                int tmp = nums[i];
                nums[i] = nums[idx1];
                nums[idx1++] = tmp;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] == 2) {
                int tmp = nums[i];
                nums[i] = nums[idx2];
                nums[idx2--] = tmp;
            }
        }
    }
};
