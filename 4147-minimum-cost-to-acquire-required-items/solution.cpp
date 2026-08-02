class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1 + cost2 < costBoth) {
            return (long long)cost1 * need1 + (long long)cost2 * need2;
        }
        long long ans = (long long)costBoth * min(need1, need2);
        if(need1 == need2) return ans;
        if(need1 > need2) {
            return ans + (long long)min(cost1, costBoth) * (need1 - need2);
        }
        return ans + (long long)min(cost2, costBoth) * (need2 - need1);
    }
};
