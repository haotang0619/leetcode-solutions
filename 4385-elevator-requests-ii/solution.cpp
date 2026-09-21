// Saw 3 hints and asked AI
class Solution {
public:
    long long INF = 1e15;
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        // Divide and sort
        vector<int> r1, r2;
        for(auto& r : requests) {
            if(r < start) r1.push_back(r);
            else if(r > start) r2.push_back(r);
        }
        sort(r1.rbegin(), r1.rend());
        sort(r2.begin(), r2.end());
        int n1 = r1.size(), n2 = r2.size();
        
        // DP
        long long dp[n1 + 1][n2 + 1][2];
        fill_n(&dp[0][0][0], (n1 + 1) * (n2 + 1) * 2, INF);
        dp[0][0][0] = dp[0][0][1] = 0;
        for(int i = 0; i <= n1; i++) {
            for(int j = 0; j <= n2; j++) {
                for(int p = 0; p < 2; p++) {
                    long long prev = p == 0 ? (i == 0 ? start : r1[i - 1]) : (j == 0 ? start : r2[j - 1]);
                    long long left = (n1 + n2 - i - j); // CHECK HINT 3 FOR THIS
                    if(i + 1 <= n1) {
                        long long d = prev - r1[i], cost = d * left;
                        dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][p] + cost);
                    }
                    if(j + 1 <= n2) {
                        long long d = r2[j] - prev, cost = d * left;
                        dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][p] + cost);
                    }
                }
            }
        }
        return min(dp[n1][n2][0], dp[n1][n2][1]);
    }
};
