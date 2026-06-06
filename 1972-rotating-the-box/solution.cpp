class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<vector<int>>> cnt(m, vector<vector<int>>({}));
        for(int i = 0; i < m; i++) {
            int cnt1 = 0, cnt2 = 0;
            for(int j = 0; j < n; j++) {
                if(boxGrid[i][j] == '#') {
                    cnt1++, cnt2++;
                } else if(boxGrid[i][j] == '.') cnt2++;
                else {
                    cnt[i].push_back({cnt1, cnt2});
                    cnt[i].push_back({-1});
                    cnt1 = 0, cnt2 = 0;
                }
            }
            if(cnt2 > 0) cnt[i].push_back({cnt1, cnt2});
        }
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for(int i = 0; i < m; i++) {
            auto rec = cnt[i];
            int j = 0;
            for(auto r : rec) {
                if(r.size() == 1) ans[j++][m - 1 - i] = '*';
                else {
                    int stone = r[0], empty = r[1];
                    j += empty;
                    for(int k = j - 1; k >= j - stone; k--) {
                        ans[k][m - 1 - i] = '#';
                    }
                }
            }
        }
        return ans;
    }
};
