class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        map<int, int> mp;
        for(int i = 1; i <= 25; i++) mp[i] = i;
        vector<int> diff;
        for(int i = 0; i < n; i++) {
            int d = (int)t[i] - (int)s[i];
            if(d == 0) continue;
            if(d < 0) d = 26 - abs(d);
            if(mp[d] > k) return false;
            diff.push_back(mp[d]);
            mp[d] += 26;
        }
        return true;
    }
};
