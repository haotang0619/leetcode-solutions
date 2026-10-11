class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = 1; i <= n; i++) ans += (n % i == 0) ? pow(nums[i - 1], 2) : 0;
        return ans;
    }
};
