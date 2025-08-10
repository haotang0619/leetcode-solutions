class Solution {
public:
    int mod = 1e9 + 7;

    int countOfPairs(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(51 * 51, 0));
        for(int idx = 0; idx < n; idx++) {
            int num = nums[idx];
            for(int i = 0, j = num - i; i <= num; i++, j--) {
                int pos = i * 51 + j;
                if(idx == 0) dp[idx][pos] = 1;
                else {
                    int prev = nums[idx - 1];
                    int now = 0;
                    for(int pi = 0, pj = prev - pi; pi <= prev; pi++, pj--) {
                        if(pi > i || pj < j) continue;
                        int ppos = pi * 51 + pj;
                        now = (now + dp[idx - 1][ppos]) % mod;
                    }
                    dp[idx][pos] = now;
                }
                if(idx == n - 1) ans = (ans + dp[idx][pos]) % mod;
            }
        }
        return ans;
    }
};
