class Solution {
public:
    int mod = 1e9 + 7;

    // Saw solutions for this concept:
    // dp[i] = Number of ways to form a string of length i using the groups seen so far
    int possibleStringCount(string word, int k) {
        vector<int> freq;
        char last = '\0';
        int cnt = 0;
        for(auto x : word) {
            if(x == last) cnt++;
            else {
                if(cnt > 0) freq.push_back(cnt);
                cnt = 1;
            }
            last = x;
        }
        if(cnt > 0) freq.push_back(cnt);

        long long total = 1;
        for(auto x : freq) total = (total * x) % mod;
        int n = freq.size();
        if(k <= n) return total;

        vector<vector<int>> dp(2, vector<int>(k, 0));
        for(int j = 1; j < k; j++) {
            if(j <= freq[0]) dp[0][j] = 1;
        }
        int now = 1, prev = 0;
        for(int i = 1; i < n; i++) {
            vector<int> p_sum(k, 0);
            for(int j = 1; j < k; j++) {
                p_sum[j] = (p_sum[j - 1] + dp[prev][j]) % mod;
            }
            for(int j = 1; j < k; j++) {
                int min_len = max(j - freq[i] - 1, 0);
                dp[now][j] = (p_sum[j - 1] - p_sum[min_len]) % mod;
            }

            now = 1 - now;
            prev = 1 - prev;
        }
        int sum = 0;
        for(auto x : dp[prev]) sum = (sum + x) % mod;
        return (total - sum + mod) % mod;
    }
};
