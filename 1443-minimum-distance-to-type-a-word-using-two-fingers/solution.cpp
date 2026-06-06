class Solution {
private:
    vector<int> charToCoord(char c) {
        int num = c - 'A';
        return {num / 6, num % 6};
    }

    int twoPosToIdx(int p1, int p2) {
        return p1 * 27 + p2;
    }

public:
    int minimumDistance(string word) {
        int n = word.size(), ans = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int>(27 * 27, INT_MAX));
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            char c = word[i - 1];
            for(int x = 0; x <= 26; x++) {
                for(int y = 0; y <= 26; y++) {
                    int idx = twoPosToIdx(x, y);
                    if(dp[i - 1][idx] == INT_MAX) continue;
                    
                    // Move finger 1
                    int newIdx1 = twoPosToIdx(c - 'A' + 1, y);
                    int dist1 = 0;
                    if(x != 0) {
                        auto coord1 = charToCoord('A' + x - 1);
                        auto coord2 = charToCoord(c);
                        dist1 = abs(coord1[0] - coord2[0]) + abs(coord1[1] - coord2[1]);
                    }
                    dp[i][newIdx1] = min(dp[i][newIdx1], dp[i - 1][idx] + dist1);
                    
                    // Move finger 2
                    int newIdx2 = twoPosToIdx(x, c - 'A' + 1);
                    int dist2 = 0;
                    if(y != 0) {
                        auto coord1 = charToCoord('A' + y - 1);
                        auto coord2 = charToCoord(c);
                        dist2 = abs(coord1[0] - coord2[0]) + abs(coord1[1] - coord2[1]);
                    }
                    dp[i][newIdx2] = min(dp[i][newIdx2], dp[i - 1][idx] + dist2);

                    // Record answer
                    if(i == n) ans = min(ans, min(dp[i][newIdx1], dp[i][newIdx2]));
                }
            }
        }
        return ans;
    }
};
