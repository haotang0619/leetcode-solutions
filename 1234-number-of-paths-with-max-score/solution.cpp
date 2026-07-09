class Solution {
public:
    int mod = 1e9 + 7;
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {1, 1}};
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        // [sum, ways]
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                char c = board[i][j];
                if(c == 'X') {
                    dp[i][j] = {0, 0};
                    continue;
                }
                if(c == 'S') {
                    dp[i][j] = {0, 1};
                    continue;
                }
                int add = (c >= '1' && c <= '9') ? (c - '0') : 0;
                pair<int, int> curr = {0, 0};
                for(auto& d : dir) {
                    auto [x, y] = d;
                    int i1 = i + x, j1 = j + y;
                    if(i1 < 0 || i1 >= n || j1 < 0 || j1 >= n) continue;
                    auto [sum, ways] = dp[i1][j1];
                    if(curr.first < sum + add && ways > 0) {
                        curr = {sum + add, ways};
                    } else if(curr.first == sum + add && ways > 0) {
                        curr.second = (curr.second + ways) % mod;
                    }
                }
                dp[i][j] = curr;
            }
        }
        return {dp[0][0].first, dp[0][0].second};
    }
};
