class Solution {
public:
    int mod = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        map<int, vector<int>> mp;
        for(auto p : points) {
            int x = p[0], y = p[1];
            if(mp.find(y) == mp.end()) mp[y] = {};
            mp[y].push_back(x);
        }
        vector<long long> v;
        for(auto [y, p] : mp) {
            long long size = p.size();
            long long cnt = (size * (size - 1) / 2) % mod;
            v.push_back(cnt);
        }
        int pSum = v[0];
        int ans = 0;
        for(int i = 1; i < v.size(); i++) {
            long long cnt = (v[i] * pSum) % mod;
            ans = (ans + (int)cnt) % mod;
            pSum += v[i];
        }
        return ans;
    }
};
