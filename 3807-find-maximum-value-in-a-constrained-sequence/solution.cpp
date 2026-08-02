class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        restrictions.push_back({0, 0});
        sort(restrictions.begin(), restrictions.end());
        int m = restrictions.size();
        vector<int> maxV(n, INT_MAX);
        
        for(int i = 0; i < m - 1; i++) {
            int l = restrictions[i][0], r = restrictions[i + 1][0];
            int lv = restrictions[i][1], rv = restrictions[i + 1][1];
            maxV[l] = lv = min(maxV[l], lv), maxV[r] = rv = min(maxV[r], rv);
            for(int j = l + 1; j <= r; j++) {
                lv += diff[j - 1], maxV[j] = min(maxV[j], lv);
            }
            for(int j = r - 1; j >= l; j--) {
                rv += diff[j], maxV[j] = min(maxV[j], rv);
            }
        }
        
        int lastl = restrictions[m - 1][0];
        int lastv = min(maxV[lastl], restrictions[m - 1][1]);
        for(int i = lastl + 1; i < n; i++) {
            lastv += diff[i - 1], maxV[i] = min(maxV[i], lastv);
        }
        
        for(int i = m - 1; i > 0; i--) {
            int l = restrictions[i - 1][0], r = restrictions[i][0];
            int lv = restrictions[i - 1][1], rv = restrictions[i][1];
            maxV[l] = lv = min(maxV[l], lv), maxV[r] = rv = min(maxV[r], rv);
            for(int j = r - 1; j >= l; j--) {
                rv += diff[j], maxV[j] = min(maxV[j], rv);
            }
            for(int j = l + 1; j <= r; j++) {
                lv += diff[j - 1], maxV[j] = min(maxV[j], lv);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) ans = max(ans, maxV[i]);
        return ans;
    }
};
