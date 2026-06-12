class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), swap = 0;
        unordered_map<int, int> mp, cnts;
        for(int i = 0; i < n; i++) mp[i] = i;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = n - 1; j >= 0; j--, cnt++) {
                if(grid[i][j] == 1) break;
            }
            cnts[i] = cnt;
        }
        for(int i = n - 1; i >= 1; i--) {
            bool hasRow = false;
            for(int j = 0; j < n; j++) {
                int idx = mp[j], tar = n - 1 - i, done = tar - 1;
                if(idx <= done) continue;
                bool valid = cnts[j] >= i;
                if(valid) {
                    hasRow = true;
                    swap += idx - tar;
                    for(int k = 0; k < n; k++) {
                        if(mp[k] >= tar && mp[k] < idx) mp[k]++;
                    }
                    mp[j] = tar;
                    break;
                }
            }
            if(!hasRow) return -1;
        }
        return swap;
    }
};
