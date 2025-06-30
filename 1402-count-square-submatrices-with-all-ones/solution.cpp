class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for(int k = 1; k <= min(m, n); k++) {
            for(int i = 0; i <= m - k; i++) {
                for(int j = 0; j <= n - k; j++) {
                    bool flag = true;
                    for(int x = i; x < i + k; x++) {
                        if(!flag) break;
                        for(int y = j; y < j + k; y++) {
                            if(matrix[x][y] == 0) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
};
