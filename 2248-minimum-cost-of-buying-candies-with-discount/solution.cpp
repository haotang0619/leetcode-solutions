class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0;
        sort(cost.rbegin(), cost.rend());
        for(int i = 0; i < cost.size(); i++) {
            ans += i % 3 == 2 ? 0 : cost[i];
        }
        return ans;
    }
};
