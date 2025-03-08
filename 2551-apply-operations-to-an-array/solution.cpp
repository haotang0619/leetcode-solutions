class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n1 = nums.size();
        int n2 = nums.size();
        while(--n1 > 0) {
            int i = n2 - n1 - 1;
            if(nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int idx1 = 0, idx2 = 0;
        for(idx2 = 0; idx2 < n2; idx2++) {
            if(nums[idx2] != 0) nums[idx1++] = nums[idx2];
        }
        while(idx1 < n2) nums[idx1++] = 0;
        return nums;
    }
};
