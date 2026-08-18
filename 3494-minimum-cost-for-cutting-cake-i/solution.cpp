class Solution {
public:
    int getAns(int memo[25][25][25][25], vector<int>& hCut, vector<int>& vCut, int l, int r, int t, int b) {
        if(memo[l][r][t][b] != -1) return memo[l][r][t][b];
        if(l + 1 == r) {
            int ans = 0;
            for(int i = t; i < b - 1; i++) ans += hCut[i];
            return memo[l][r][t][b] = ans;
        }
        if(t + 1 == b) {
            int ans = 0;
            for(int i = l; i < r - 1; i++) ans += vCut[i];
            return memo[l][r][t][b] = ans;
        }
        int ans = INT_MAX;
        for(int i = t; i < b - 1; i++) {
            ans = min(ans, hCut[i] + getAns(memo, hCut, vCut, l, r, t, i + 1) + getAns(memo, hCut, vCut, l, r, i + 1, b));
        }
        for(int i = l; i < r - 1; i++) {
            ans = min(ans, vCut[i] + getAns(memo, hCut, vCut, l, i + 1, t, b) + getAns(memo, hCut, vCut, i + 1, r, t, b));
        }
        return memo[l][r][t][b] = ans;
    }
    
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int memo[25][25][25][25];
        memset(memo, -1, sizeof(memo));
        return getAns(memo, horizontalCut, verticalCut, 0, n, 0, m);
    }
};
