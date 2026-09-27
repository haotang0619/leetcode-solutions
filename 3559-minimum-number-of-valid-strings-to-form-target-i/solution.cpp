class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        unordered_set<string> st;
        for(auto& word : words) {
            string now;
            for(auto& c : word) now += c, st.insert(now);
        }
        int n = target.size();
        vector<int> dp(n, INT_MAX);
        for(int l = 0, r = 0; l < n; l++) {
            if(l > r) break;
            string now = target.substr(l, r - l + 1);
            while(r < n && st.contains(now)) {
                dp[r++] = (l > 0 ? dp[l - 1] : 0) + 1;
                if(r < n) now += target[r];
            }
        }
        return dp[n - 1] == INT_MAX ? -1 : dp[n - 1];
    }
};
