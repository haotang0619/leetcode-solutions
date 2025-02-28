class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxHere = nums[0], maxSum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            maxHere = max(maxHere + nums[i], nums[i]);
            maxSum = max(maxHere, maxSum);
        }
        return maxSum;
    }
};
