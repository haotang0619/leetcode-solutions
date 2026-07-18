class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(), mx = -1;
        for(auto& num : nums) mx = max(mx, num), num = gcd(mx, num);
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i = 0, j = n - 1; i < j; i++, j--) ans += gcd(nums[i], nums[j]);
        return ans;
    }
};
