class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long sum = 0;
        vector<long long> rSum(m, 0), cSum(n, 0);
        unordered_map<int, vector<int>> rmp, cmp;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rSum[i] += grid[i][j];
                cSum[j] += grid[i][j];
                sum += grid[i][j];
                rmp[grid[i][j]].push_back(i);
                cmp[grid[i][j]].push_back(j);
            }
        }
        for(auto& [val, v] : cmp) sort(v.begin(), v.end());

        // Horizontal
        long long pSum = 0;
        for(int i = 0; i < m - 1; i++) {
            long long sum1 = pSum + rSum[i], sum2 = sum - sum1;
            long long diff = abs(sum1 - sum2);
            if(diff == 0) return true;
            pSum += rSum[i];
            if(!rmp.contains(diff)) continue;
            if(sum1 > sum2) {
                int idx = lower_bound(rmp[diff].begin(), rmp[diff].end(), i + 1) - rmp[diff].begin();
                if(idx != 0) {
                    if(n > 1) {
                        if(i > 0) return true;
                        // i == 0
                        if(grid[i][0] == diff || grid[i][n - 1] == diff) return true;
                    } else {
                        if(grid[0][0] == diff || grid[i][0] == diff) return true;
                    }
                }
            } else {
                int idx = lower_bound(rmp[diff].begin(), rmp[diff].end(), i + 1) - rmp[diff].begin();
                if(idx != rmp[diff].size()) {
                    if(n > 1) {
                        if(i < m - 2) return true;
                        // i == m - 2 => check m - 1
                        if(grid[i + 1][0] == diff || grid[i + 1][n - 1] == diff) return true;
                    } else {
                        if(grid[i + 1][0] == diff || grid[m - 1][0] == diff) return true;
                    }
                }
            }
        }

        // Vertical
        pSum = 0;
        for(int j = 0; j < n - 1; j++) {
            long long sum1 = pSum + cSum[j], sum2 = sum - sum1;
            long long diff = abs(sum1 - sum2);
            if(diff == 0) return true;
            pSum += cSum[j];
            if(!cmp.contains(diff)) continue;
            if(sum1 > sum2) {
                int idx = lower_bound(cmp[diff].begin(), cmp[diff].end(), j + 1) - cmp[diff].begin();
                if(idx != 0) {
                    if(m > 1) {
                        if(j > 0) return true;
                        // j == 0
                        if(grid[0][j] == diff || grid[m - 1][j] == diff) return true;
                    } else {
                        if(grid[0][0] == diff || grid[0][j] == diff) return true;
                    }
                }
            } else {
                int idx = lower_bound(cmp[diff].begin(), cmp[diff].end(), j + 1) - cmp[diff].begin();
                if(idx != cmp[diff].size()) {
                    if(m > 1) {
                        if(j < n - 2) return true;
                        // j == n - 2 => check n - 1
                        if(grid[0][j + 1] == diff || grid[m - 1][j + 1] == diff) return true;
                    } else {
                        if(grid[0][j + 1] == diff || grid[0][n - 1] == diff) return true;
                    }
                }
            }
        }
        return false;
    }
};
