class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                long long x = nums[i], y = nums[j];
                ans = max(ans, x * y / gcd(x, y) / gcd(x, y));
            }
        }
        return ans;
    }
};
