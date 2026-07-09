// Saw solutions
class Solution {
public:
    int maxDist = 1e6 + 7;
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        int n = houses.size();
        vector<int> pSum(n + 1, 0);
        for(int i = 1; i <= n; i++) pSum[i] = pSum[i - 1] + houses[i - 1];
        vector<vector<int>> dist(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int mid = (i + j) / 2;
                int pos = houses[mid];
                // Houses between [i, mid]
                dist[i][j] += pos * (mid - i + 1) - (pSum[mid + 1] - pSum[i]);
                // Houses between [mid + 1, j]
                if(mid + 1 <= j) {
                    dist[i][j] += (pSum[j + 1] - pSum[mid + 1]) - pos * (j - mid);
                }
            }
        }
        
        // Partition DP
        vector<vector<int>> dp(k + 1, vector<int>(n, maxDist)); 
        // DP status: [Cuts count, Opt. answer from [i, n - 1]]
        for(int i = 0; i < n; i++) dp[1][i] = dist[i][n - 1];
        for(int x = 2; x <= k; x++) {
            for(int j = n - x; j >= 0; j--) {
                for(int i = j; i >= 0; i--) {
                    dp[x][i] = min(dp[x][i], dist[i][j] + dp[x - 1][j + 1]);
                }
            }
        }
        return dp[k][0];
    }
};
