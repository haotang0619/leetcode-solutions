class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> cnt(r, vector<int>(c, 0));
        for(int j = 0; j < c; j++) {
            int now = 0;
            for(int i = r - 1; i >= 0; i--) {
                if(matrix[i][j] == '1') {
                    now++;
                } else now = 0;
                cnt[i][j] = now;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                int minCnt = cnt[i][j];
                for(int k = j; k < c; k++) {
                    if(cnt[i][k] == 0) break;
                    minCnt = min(minCnt, cnt[i][k]);
                    ans = max(ans, minCnt * (k - j + 1));
                }
            }
        }
        return ans;
    }
};
