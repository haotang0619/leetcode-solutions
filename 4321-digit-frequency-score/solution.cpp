class Solution {
public:
    int digitFrequencyScore(int n) {
        string s = to_string(n);
        map<int, int> mp;
        for(auto c : s) mp[c - '0']++;
        int ans = 0;
        for(auto &x : mp) ans += x.first * x.second;
        return ans;
    }
};
