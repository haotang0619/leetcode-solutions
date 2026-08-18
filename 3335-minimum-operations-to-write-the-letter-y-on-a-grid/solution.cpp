class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        vector<int> cntY(3, 0), cntOther(3, 0);
        int n = grid.size(), yCnt = 0, otherCnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(
                    (i < n / 2 && (i == j || i + j + 1 == n)) ||
                    (i >= n / 2 && j == n / 2)
                ) {
                    yCnt++, cntY[grid[i][j]]++;
                }
                else otherCnt++, cntOther[grid[i][j]]++;
            }
        }
        int ans = INT_MAX;
        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                if(x == y) continue;
                int now = (yCnt - cntY[x]) + (otherCnt - cntOther[y]);
                ans = min(ans, now);
            }
        }
        return ans;
    }
};
