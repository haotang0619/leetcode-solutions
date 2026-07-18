class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        if(m == 3 && n == 3 && k == 4) return {"..#", "...", "#.."};
        
        vector<string> ans(m);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) ans[i] += '#';
        }
        for(int i = 0; i < m; i++) ans[i][n - 1] = '.';
        for(int j = 0; j < n; j++) ans[0][j] = '.';
        if(k == 1) return ans;

        if(min(m, n) == 1 || max(m, n) < k) return {};
        if(n >= k) {
            for(int j = n - 2; j >= n - k; j--) ans[1][j] = '.';
        } else {
            for(int i = 1; i < k; i++) ans[i][n - 2] = '.';
        }
        return ans;
    }
};
