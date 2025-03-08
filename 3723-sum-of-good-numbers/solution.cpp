class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if((i < k || nums[i - k] < nums[i]) && (i >= nums.size() - k || nums[i + k] < nums[i])) ans += nums[i];
        }
        return ans;
    }
};
