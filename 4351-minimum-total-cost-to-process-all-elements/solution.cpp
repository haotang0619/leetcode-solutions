class Solution {
public:
    long long mod = 1e9 + 7;
    int minimumCost(vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long times = (sum / k + (sum % k > 0)) % mod;
        return (times * (times - 1) / 2) % mod;
    }
};
