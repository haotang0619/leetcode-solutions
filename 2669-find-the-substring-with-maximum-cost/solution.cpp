class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> v(26);
        iota(v.begin(), v.end(), 1);
        for(int i = 0; i < chars.size(); i++) v[chars[i] - 'a'] = vals[i];
        int ans = 0, now = 0;
        for(auto& c : s) {
            now += v[c - 'a'];
            ans = max(ans, now);
            if(now < 0) now = 0;
        }
        return ans;
    }
};
