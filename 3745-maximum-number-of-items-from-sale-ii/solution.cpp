class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> v(n + 1, 0);
        for(auto &i : items) v[i[0]]++;

        vector<int> freeCopies(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(v[i] == 0) continue;
            for(int j = i; j <= n; j += i) freeCopies[i] += v[j];
            freeCopies[i]--;
        }

        // Saw hint 3 & 4
        vector<vector<double>> newItems; // [copies/price, copies, price, amount]
        for(auto &i : items) {
            int factor = i[0], price = i[1];
            newItems.push_back({double(price), 1, double(price), -1});
            if(freeCopies[factor] > 0) {
                newItems.push_back({double(price) / 2, 2, double(price), double(freeCopies[factor])});
            }
        }
        sort(newItems.begin(), newItems.end());
        int idx = 0, ans = 0;
        while(budget > 0 && idx < newItems.size()) {
            double copies = newItems[idx][1], price = newItems[idx][2], amount = newItems[idx][3];
            if(amount > 0) {
                int amt = min(budget / price, amount);
                budget -= price * amt;
                ans += copies * amt;
            } else {
                ans += budget / price;
                budget %= int(price);
            }
            idx++;
        }
        return ans;
    }
};
