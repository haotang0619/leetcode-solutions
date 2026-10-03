class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sk;
        int ans = 0, n = s.size();
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(s[i - 1] == '(') sk.push(i);
            else {
                if(sk.size() > 0) {
                    int prev = sk.top();
                    sk.pop();
                    dp[i] = dp[prev - 1] + (i - prev + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};
