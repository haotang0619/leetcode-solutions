class Solution {
public:
    int mod = 1e9 + 7;
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int i = 1, n = nextVisit.size();
        vector<int> dp(n - 1, 2);
        for(int i = 1; i < n - 1; i++) {
            dp[i] = (dp[i] + dp[i - 1]) % mod;
            int next = nextVisit[i];
            if(next != i) {
                int to_add = (mod + dp[i - 1] - (next > 0 ? dp[next - 1] : 0)) % mod;
                dp[i] = (dp[i] + to_add) % mod;
            }
        }
        return dp.back();
    }
};
