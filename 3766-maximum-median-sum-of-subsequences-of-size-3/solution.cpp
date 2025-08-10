class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<long long>());
        long long ans = 0;
        for(int i = 0; i < nums.size() / 3; i++) {
            ans += nums[2 * i + 1];
        }
        return ans;
    }
};
