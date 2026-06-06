class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> cnts(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(int j = n - 1; j >= 0; j--) {
                cnt = mat[i][j] == 1 ? cnt + 1 : 0;
                cnts[i][j] = cnt;
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int minCnt = cnts[i][j];
                for(int k = i; k < m && minCnt > 0; k++) {
                    minCnt = min(minCnt, cnts[k][j]);
                    ans += minCnt;
                }
            }
        }
        return ans;
    }
};
