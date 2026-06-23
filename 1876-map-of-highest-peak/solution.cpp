class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> qu;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    qu.push({i, j});
                }
            }
        }
        while(!qu.empty()) {
            auto [i, j] = qu.front();
            qu.pop();
            if(i > 0 && ans[i - 1][j] == -1) {
                ans[i - 1][j] = ans[i][j] + 1;
                qu.push({i - 1, j});
            }
            if(i < m - 1 && ans[i + 1][j] == -1) {
                ans[i + 1][j] = ans[i][j] + 1;
                qu.push({i + 1, j});
            }
            if(j > 0 && ans[i][j - 1] == -1) {
                ans[i][j - 1] = ans[i][j] + 1;
                qu.push({i, j - 1});
            }
            if(j < n - 1 && ans[i][j + 1] == -1) {
                ans[i][j + 1] = ans[i][j] + 1;
                qu.push({i, j + 1});
            }
        }
        return ans;
    }
};
