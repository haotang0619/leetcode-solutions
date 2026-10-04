class Solution {
public:
    long long MN = -1e15, MX = 1e15;
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pSum1(n + 1, 0), pSum2(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            auto& p1 = (i & 1) ? pSum1 : pSum2;
            auto& p2 = (i & 1) ? pSum2 : pSum1;
            p1[i] = p1[i - 1] + nums[i - 1];
            p2[i] = p2[i - 1] - nums[i - 1];
        }
        
        long long backMx[n][2], frontMx[n][2];
        long long mx1 = MN, mx2 = MN;
        for(int i = n - 1; i >= 0; i--) {
            int isOdd = (i & 1);
            mx1 = max(mx1, pSum1[i + 1]), mx2 = max(mx2, pSum2[i + 1]);
            backMx[i][isOdd] = mx1 - pSum1[i];
            backMx[i][1 - isOdd] = mx2 - pSum2[i];
        }
        long long mn1 = MX, mn2 = MX;
        for(int i = 0; i < n; i++) {
            if(i & 1) {
                mn2 = min(mn2, pSum2[i]);
                frontMx[i][0] = pSum2[i + 1] - mn2;
                frontMx[i][1] = pSum1[i + 1] - mn1;
            } else {
                mn1 = min(mn1, pSum1[i]);
                frontMx[i][0] = pSum1[i + 1] - mn1;
                frontMx[i][1] = pSum2[i + 1] - mn2;
            }
        }

        long long ans = MN;
        for(int i = 0; i < n; i++) {
            ans = max({ans, frontMx[i][0], frontMx[i][1]});
            if(i + 2 < n) {
                ans = max(ans, frontMx[i][0] + backMx[i + 2][1]);
                ans = max(ans, frontMx[i][1] + backMx[i + 2][0]);
            }
        }
        return ans;
    }
};
