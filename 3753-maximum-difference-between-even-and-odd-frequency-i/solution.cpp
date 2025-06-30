class Solution {
public:
    int maxDifference(string s) {
        map<char, int> mp;
        for(auto x : s) {
            if(mp.find(x) == mp.end()) mp[x] = 0;
            mp[x]++;
        }
        int max_odd = 0, min_even = INT_MAX;
        for(auto x : mp) {
            if(x.second % 2 == 1) max_odd = max(max_odd, x.second);
            else min_even = min(min_even, x.second);
        }
        return max_odd - min_even;
    }
};
