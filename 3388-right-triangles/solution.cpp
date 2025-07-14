class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> cnts(n, 0);
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) cnts[j] += grid[i][j];
        }

        for(int i = 0; i < m; i++) {
            int cnt1 = 0, cnt2 = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    cnt1++;
                    cnt2 += (cnts[j] - 1);
                }
            }
            ans += ((long long)cnt1 - 1) * cnt2;
        }
        return ans;
    }
};
