class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m - 1].size();
        if(m == 1) return triangle[0][0];
        vector<int> dp = {triangle[0][0]};
        int ans = INT_MAX;
        for(int i = 1; i < m; i++) {
            vector<int> dp1(i + 1, INT_MAX);
            for(int j = 0; j <= i; j++) {
                if(j > 0) dp1[j] = min(dp1[j], dp[j - 1] + triangle[i][j]);
                if(j < i) dp1[j] = min(dp1[j], dp[j] + triangle[i][j]);
                if(i == m - 1) ans = min(ans, dp1[j]);
            }
            dp = dp1;
        }
        return ans;
    }
};
