class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp1, mp2;
        for(auto x : basket1) mp1[x]++, mp2[x]++;
        for(auto x : basket2) mp2[x]++;
        vector<int> v;
        long long minC = 1e9;
        for(auto [x, cnt] : mp2) {
            if(cnt % 2 == 1) return -1;
            minC = min(minC, (long long)x);
            int tar = cnt / 2;
            for(int i = min(mp1[x], tar); i < max(mp1[x], tar); i++) {
                v.push_back(x);
            }
        }
        sort(v.begin(), v.end());
        int idx = v.size() / 2;
        if(idx == 0) return 0;
        long long ans = -1, now = 0;
        for(int i = 0; i <= idx; i++) {
            long long res = minC * (idx - i) * 2 + now;
            if(ans == -1) ans = res;
            else ans = min(ans, res);
            now += v[i];
        }
        return ans;
    }
};
