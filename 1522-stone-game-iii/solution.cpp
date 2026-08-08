// Figured out by myself
class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n + 1, INT_MIN); // Optimial scores from here
        dp[n] = 0;
        dp[n - 1] = stones[n - 1];
        int sum = stones[n - 1];
        if(n >= 2) {
            dp[n - 2] = max(stones[n - 2] + stones[n - 1], stones[n - 2]);
            sum += stones[n - 2];
            for(int i = n - 3; i >= 0; i--) {
                sum += stones[i];
                int take1 = sum - dp[i + 1];
                int take2 = sum - dp[i + 2];
                int take3 = sum - dp[i + 3];
                dp[i] = max(max(take1, take2), take3);
            }
        }
        if(dp[0] * 2 == sum) return "Tie";
        return dp[0] * 2 > sum ? "Alice" : "Bob";
    }
};
