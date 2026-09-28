class Solution {
public:
    using ull = unsigned long long;
    ull base = 131;
    int minValidStrings(vector<string>& words, string target) {
        unordered_set<ull> st;
        for(auto& word : words) {
            ull hash = 0;
            for(auto& c : word) hash = hash * base + (c - 'a' + 1), st.insert(hash);
        }
        
        int n = target.size();
        vector<ull> pow(n + 1, 1), rh(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            pow[i] = pow[i - 1] * base;
            rh[i] = rh[i - 1] * base + (target[i - 1] - 'a' + 1);
        }
        
        vector<int> dp(n, INT_MAX);
        for(int l = 0, r = 0; r < n; l++) {
            if(l > r) break;

            int now = (l > 0 ? dp[l - 1] : 0) + 1;
            int l1 = r, r1 = n - 1;
            while(l1 < r1) {
                int m = (l1 + r1) / 2;
                ull hash = rh[m + 1] - rh[l] * pow[m - l + 1];
                if(st.contains(hash)) l1 = m + 1;
                else r1 = m;
            }
            ull hash = rh[l1 + 1] - rh[l] * pow[l1 - l + 1];
            if(st.contains(hash)) l1++;
            while(r < l1) dp[r++] = now;
        }
        return dp[n - 1] == INT_MAX ? -1 : dp[n - 1];
    }
};
