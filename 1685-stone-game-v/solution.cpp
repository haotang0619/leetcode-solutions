class Solution {
public:
    int findAns(vector<vector<int>>& memo, vector<int>& pSum, int l, int r) {
        if(memo[l][r] != -1) return memo[l][r];
        
        int ans = 0;
        if(l == r) return memo[l][r] = ans;
        
        for(int i = l; i < r; i++) {
            int lSum = pSum[i + 1] - pSum[l], rSum = pSum[r + 1] - pSum[i + 1];
            if(lSum < rSum) ans = max(ans, lSum + findAns(memo, pSum, l, i));
            else if(lSum > rSum) ans = max(ans, rSum + findAns(memo, pSum, i + 1, r));
            else {
                ans = max({
                    ans, 
                    lSum + findAns(memo, pSum, l, i), 
                    rSum + findAns(memo, pSum, i + 1, r)
                });
            }
        }
        return memo[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pSum(n + 1, 0);
        for(int i = 1; i <= n; i++) pSum[i] = pSum[i - 1] + stoneValue[i - 1];
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return findAns(memo, pSum, 0, n - 1);
    }
};
