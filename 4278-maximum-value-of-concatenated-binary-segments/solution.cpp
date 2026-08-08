class Solution {
public:
    int mod = 1e9 + 7;
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        vector<string> v(n);
        for(int i = 0; i < n; i++) {
            string s;
            for(int x = 0; x < nums1[i]; x++) s += '0';
            for(int x = 0; x < nums0[i]; x++) s += '1';
            v[i] = s;
        }
        sort(v.rbegin(), v.rend());
        long long ans = 0, base = 1;
        for(auto& s : v) {
            reverse(s.begin(), s.end());
            for(auto& c : s) {
                int d = (c == '0') ? 1 : 0;
                ans = (ans + d * base) % mod;
                base = (base * 2) % mod;
            }
        }
        return ans;
    }
};
