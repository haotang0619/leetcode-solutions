class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long ans = 0;
        int d = 1, m = values.size(), n = values[0].size();
        vector<int> indices(m, n - 1);
        while(true) {
            int pick = -1, mn = INT_MAX;
            for(int i = 0; i < m; i++) {
                if(indices[i] == -1) continue;
                if(values[i][indices[i]] < mn) {
                    pick = i, mn = values[i][indices[i]];
                }
            }
            if(pick == -1) break;
            ans += (d++) * (long long)values[pick][indices[pick]--];
        }
        return ans;
    }
};
