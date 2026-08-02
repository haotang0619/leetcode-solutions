class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for(auto& c : word) mp[c]++;
        vector<pair<char, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });
        int ans = 0;
        for(int i = 0; i < v.size(); i++) ans += (i / 8 + 1) * v[i].second;
        return ans;
    }
};
