class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int ans = 1, maxNow = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] >= maxNow) {
                ans++;
                maxNow = nums[i];
            }
        }
        return ans;
    }
};
