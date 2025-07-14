class Solution {
public:
    // Saw solutions, but should not
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> comb;
        int n = scores.size();
        for(int i = 0; i < n; i++) comb.push_back({ages[i], scores[i]});
        sort(comb.begin(), comb.end(), greater<pair<int, int>>());
        
        int ans = 0;
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++) {
            int score = comb[i].second;
            dp[i] = score;
            for(int j = 0; j < i; j++) {
                if(comb[j].second >= comb[i].second) {
                    dp[i] = max(dp[i], dp[j] + score);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
