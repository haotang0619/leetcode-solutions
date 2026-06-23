class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        vector<set<pair<int, int>>> dp(n3 + 1);
        dp[0].insert({-1, -1});
        for(int i = 1; i <= n3; i++) {
            bool valid = false;
            for(auto &x : dp[i - 1]) {
                auto [x1, x2] = x;
                if(s1[x1 + 1] == s3[i - 1]) {
                    valid = true;
                    dp[i].insert({x1 + 1, x2});
                }
                if(s2[x2 + 1] == s3[i - 1]) {
                    valid = true;
                    dp[i].insert({x1, x2 + 1});
                }
            }
            if(!valid) return false;
        }
        return dp[n3].contains({n1 - 1, n2 - 1});
    }
};
