class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i = 0, j = 0, m = mat.size(), n = mat[0].size(), dir = 0;
        vector<int> ans;
        do {
            ans.push_back(mat[i][j]);
            if(dir == 0) {
                i--, j++;
                if(j >= n) i += 2, j = n - 1, dir = 1;
                else if(i < 0) i = 0, dir = 1;
            } else {
                i++, j--;
                if(i >= m) j += 2, i = m - 1, dir = 0;
                else if(j < 0) j = 0, dir = 0;
            }
        } while(ans.size() < m * n);
        return ans;
    }
};
