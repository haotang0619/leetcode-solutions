class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string s(n, '#');
        vector<string> ans(m, s);
        for(int i = 0; i < m; i++) ans[i][n - 1] = '.';
        for(int j = 0; j < n; j++) ans[0][j] = '.';
        return ans;
    }
};
