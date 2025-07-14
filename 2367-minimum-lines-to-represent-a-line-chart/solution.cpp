class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if(n == 1) return 0;

        sort(stockPrices.begin(), stockPrices.end());
        int ans = 0, preDiffX = INT_MAX, preDiffY = INT_MAX;
        for(int i = 1; i < n; i++) {
            int diffX = stockPrices[i][0] - stockPrices[i - 1][0];
            int diffY = stockPrices[i][1] - stockPrices[i - 1][1];
            int gcd = __gcd(diffX, diffY);
            gcd = gcd == 0 ? 1 : gcd;
            diffX /= gcd;
            diffY /= gcd;
            if(diffX != preDiffX || diffY != preDiffY) {
                ans++;
                preDiffX = diffX;
                preDiffY = diffY;
            }
        }
        return ans;
    }
};
