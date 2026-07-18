// Saw editorial
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        map<int, int> dp; // dp[diff(= taller - shorter)] = taller
        dp[0] = 0;
        for(int& r : rods) {
            map<int, int> dp1 = dp;
            for(auto& [diff, taller] : dp) {
                int shorter = taller - diff;
                // 1. r to taller
                dp1[diff + r] = max(dp1[diff + r], taller + r);
                // 2. r to shorter
                dp1[abs(diff - r)] = max(dp1[abs(diff - r)], max(taller, shorter + r));
            }
            dp = dp1;
        }
        return dp[0];
    }
};
