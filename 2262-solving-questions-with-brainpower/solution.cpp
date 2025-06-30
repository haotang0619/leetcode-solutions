class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int size = questions.size();
        vector<long long> dp(size, 0);
        for(int i = size - 1; i >= 0; i--) {
            long long val1 = i + 1 < size ? dp[i + 1] : 0LL;
            long long val2 = questions[i][0];
            int pos = i + questions[i][1] + 1;
            if(pos < size) val2 += dp[pos];
            dp[i] = max(val1, val2);
        }
        return dp[0];
    }
};
