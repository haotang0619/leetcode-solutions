class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<vector<int>> newItems; // [cost, copies, unlimited]
        for(auto i : items) newItems.push_back({i[1], 1, 1});
        for(int i = 0; i < n; i++) {
            int copies = 1;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(items[j][0] % items[i][0] == 0) copies++;
            }
            if(copies > 1) newItems.push_back({items[i][1], copies, 0});
        }
        
        vector<int> dp(budget + 1, 0);
        int nn = newItems.size();
        for(int i = 0; i < nn; i++) {
            int cost = newItems[i][0];
            int copies = newItems[i][1];
            int unlimited = newItems[i][2];
            if(unlimited == 0) {
                for(int j = budget; j >= cost; j--) {
                    dp[j] = max(dp[j], dp[j - cost] + copies);
                }
            } else {
                for(int j = cost; j <= budget; j++) {
                    dp[j] = max(dp[j], dp[j - cost] + copies);
                }
            }
        }

        return dp[budget];
    }
};
