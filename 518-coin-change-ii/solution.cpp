// Infinite Knapsack Problem
class Solution {
public:
    using ull = unsigned long long;

    int change(int amount, vector<int>& coins) {
        vector<ull> dp(amount + 1, 0);
        dp[0] = 1;
        for(auto& c : coins) {
            for(int i = c; i <= amount; i++) dp[i] += dp[i - c];
        }
        return dp[amount];
    }
};
