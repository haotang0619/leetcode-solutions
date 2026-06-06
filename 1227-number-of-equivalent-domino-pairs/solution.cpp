class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> mp;
        for(auto d : dominoes) {
            int x = d[0] < d[1] ? d[0] : d[1], y = d[0] < d[1] ? d[1] : d[0];
            mp[x * 10 + y]++;
        }
        int ans = 0;
        for(auto [d, cnt] : mp) ans += cnt * (cnt - 1) / 2;
        return ans;
    }
};
