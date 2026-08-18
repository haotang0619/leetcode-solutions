class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        int n = prices.size(), m = discounts.size();
        double ans = 0;
        for(int i = 0, j = 0; i < n; i++) {
            if(j < m) ans += (double)prices[i] * (100 - discounts[j++]) / 100;
            else ans += prices[i];
        }
        return ans;
    }
};
