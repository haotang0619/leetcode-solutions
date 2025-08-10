class Solution {
public:
    // Saw all hints
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<vector<bool>> dp(n, vector<bool>(1001, false));
        for(int i = 0; i < n; i++) dp[i][0] = true;

        for(int k = 0; k <= m; k++) {
            bool isValid = true;
            for(int i = 0; i < n; i++) {
                if(!dp[i][nums[i]]) {
                    isValid = false;
                    break;
                }
            }
            if(isValid) return k;
            if(k >= m) break;

            auto q = queries[k];
            int l = q[0], r = q[1], v = q[2];
            for(int i = l; i <= r; i++) {
                for(int j = 1000; j - v >= 0; j--) {
                    if(dp[i][j - v]) dp[i][j] = true;
                }
            }
        }
        return -1;
    }
};
