// Figured out by myself
class Solution {
public:
    int findMaxOfMin(vector<vector<int>>& grid, int ans, int filt) {
        int cap = ans + filt, maxOfMin = 0;
        for(auto& row : grid) {
            int minVal = INT_MAX;
            for(auto& cell : row) {
                if((cell | cap) > cap) continue;
                int val = cell & filt;
                minVal = min(minVal, val);
            }
            if(minVal != INT_MAX) maxOfMin = max(maxOfMin, minVal);
        }
        return maxOfMin;
    }

    int minimumOR(vector<vector<int>>& grid) {
        int ans = 0, filt = INT_MAX;
        int maxOfMin = findMaxOfMin(grid, ans, filt);
        while(maxOfMin > 0) {
            int p = log2(maxOfMin);
            ans |= (1 << p);
            filt = (1 << p) - 1;
            maxOfMin = findMaxOfMin(grid, ans, filt);
        }
        return ans;
    }
};
