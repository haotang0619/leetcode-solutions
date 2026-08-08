class Solution {
public:
    int mod = 1e9 + 7;
    int countArrays(vector<int>& digitSum) {
        vector<int> sums(5001, 0), dp(5001, 0);
        for(int num = 0; num <= 5000; num++) {
            string s = to_string(num);
            int sum = 0;
            for(auto& c : s) sum += (c - '0');
            sums[num] = sum;
        }
        
        int ans = 0, n = digitSum.size();
        for(int i = 0; i < n; i++) {
            int pSum = 0;
            vector<int> dp1(5001, 0);
            for(int num = 0; num <= 5000; num++) {
                pSum = (pSum + dp[num]) % mod;
                if(digitSum[i] == sums[num]) {
                    dp1[num] = (i == 0) ? 1 : pSum;
                    if(i == n - 1) ans = (ans + dp1[num]) % mod;
                }
            }
            dp = dp1;
        }
        return ans;
    }
};
