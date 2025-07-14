class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> v(m, vector<int>(n, 0));
        for(int j = 0; j < n; j++) {
            int cnt = 0;
            for(int i = m - 1; i >= 0; i--) {
                if(matrix[i][j] == 0) cnt = 0;
                else v[i][j] = ++cnt;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < m; i++) {
            sort(v[i].begin(), v[i].end());
            for(int j = 0; j < n; j++) {
                ans = max(ans, v[i][j] * (n - j));
            }
        }
        return ans;
    }
};
