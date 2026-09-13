class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0, n = img1.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img2[i][j] == 1) v.push_back({i, j});
            }
        }
        for(int i = -n; i <= n; i++) {
            for(int j = -n; j <= n; j++) {
                int cnt = 0;
                for(auto& [i1, j1] : v) {
                    if(i1 + i < 0 || i1 + i >= n || j1 + j < 0 || j1 + j >= n) continue;
                    if(img1[i1 + i][j1 + j] == 1) cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
