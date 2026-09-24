class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size();
        bool xy[51][51]{}, yz[51][51]{}, xz[51][51]{};
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                for(int z = 0; z < grid[x][y]; z++) {
                    if(!xy[x][y]) xy[x][y] = true, ans++;
                    if(!yz[y][z]) yz[y][z] = true, ans++;
                    if(!xz[x][z]) xz[x][z] = true, ans++;
                }
            }
        }
        return ans;
    }
};
