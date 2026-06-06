class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int maxNow = weight[0], ans = 0;
        for(int i = 1; i < weight.size(); i++) {
            maxNow = max(maxNow, weight[i]);
            if(weight[i] < maxNow) {
                ans++;
                i++;
                if(i < weight.size()) maxNow = weight[i];
            }
        }
        return ans;
    }
};
