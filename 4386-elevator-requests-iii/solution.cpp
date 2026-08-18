class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        int m = requests.size();
        int mm = (1 << m);
        vector<vector<long long>> dp(mm, vector(m, LLONG_MAX));
        for(int i = 0; i < m; i++) {
            dp[1 << i][i] = max(abs(requests[i][1] - start), requests[i][0]);
        }
        long long ans = LLONG_MAX;
        for(int x = 1; x < mm; x++) {
            for(int i = 0; i < m; i++) {
                if((x & (1 << i)) == 0) continue;
                int xx = x - (1 << i);
                for(int j = 0; j < m; j++) {
                    if(j == i) continue;
                    if((x & (1 << j)) == 0) continue;
                    int arr = requests[i][0], f1 = requests[i][1], f2 = requests[j][1];
                    dp[x][i] = min(dp[x][i], max((long long)arr, dp[xx][j] + abs(f1 - f2)));
                }
                if(x == mm - 1) ans = min(ans, dp[x][i]);
            }
        }
        return ans;
    }
};
