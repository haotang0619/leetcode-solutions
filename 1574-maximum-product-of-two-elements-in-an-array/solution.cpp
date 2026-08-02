class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        for(auto& num : nums) num--;
        sort(nums.begin(), nums.end());
        return max(nums[n - 1] * nums[n - 2], nums[0] * nums[n - 1]);
    }
};
