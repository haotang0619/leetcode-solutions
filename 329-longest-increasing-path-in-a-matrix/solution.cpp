class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> e(m * n, vector<int>({}));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int idx = i * n + j;
                if(i > 0 && matrix[i - 1][j] > matrix[i][j]) {
                    e[idx].push_back(idx - n);
                }
                if(i < m - 1 && matrix[i + 1][j] > matrix[i][j]) {
                    e[idx].push_back(idx + n);
                }
                if(j > 0 && matrix[i][j - 1] > matrix[i][j]) {
                    e[idx].push_back(idx - 1);
                }
                if(j < n - 1 && matrix[i][j + 1] > matrix[i][j]) {
                    e[idx].push_back(idx + 1);
                }
            }
        }
        stack<pair<int, int>> sk;
        int ans = 1;
        vector<int> maxLen(m * n, 1);
        for(int i = 0; i < m * n; i++) {
            sk.push({i, 1});
            while(!sk.empty()) {
                auto [node, len] = sk.top();
                sk.pop();
                ans = max(ans, len);
                maxLen[node] = max(maxLen[node], len);
                for(auto x : e[node]) {
                    if(maxLen[node] >= len + 1) continue;
                    sk.push({x, len + 1});
                }
            }
        }
        return ans;
    }
};
