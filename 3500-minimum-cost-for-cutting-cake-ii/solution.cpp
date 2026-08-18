class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<pair<int, int>> v;
        for(auto& c : horizontalCut) v.push_back({c, 0});
        for(auto& c : verticalCut) v.push_back({c, 1});
        sort(v.rbegin(), v.rend());
        int hcnt = 1, vcnt = 1;
        long long ans = 0;
        for(auto& [c, type] : v) {
            if(type == 0) ans += (long long)c * hcnt, vcnt++;
            else ans += (long long)c * vcnt, hcnt++;
        }
        return ans;
    }
};
