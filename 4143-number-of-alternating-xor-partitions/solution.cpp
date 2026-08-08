class Solution {
public:
    int mod = 1e9 + 7;
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int n = nums.size();
        unordered_map<int, pair<int, int>> dp;
        int acc = 0;
        for(int i = 0; i < n; i++) {
            acc ^= nums[i];
            int prev1 = acc ^ target1, prev2 = acc ^ target2;
            int add1 = 0, add2 = 0;
            if(dp.contains(prev1)) add1 = dp[prev1].second;
            if(dp.contains(prev2)) add2 = dp[prev2].first;
            if(acc == target1) add1++;
            if(i == n - 1) return (add1 + add2) % mod;
            dp[acc].first = (dp[acc].first + add1) % mod;
            dp[acc].second = (dp[acc].second + add2) % mod;
        }
        return 0;
    }
};
