class Solution {
public:
    int modulo = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        unordered_map<char, vector<int>> ump;
        for(char c = 'a'; c <= 'z'; c++) ump[c] = {0, 0};
        for(auto x : s) ump[x][0]++;
        int idx = 0;
        for(int i = 0; i < t; i++) {
            int prev = idx;
            idx = 1 - idx;
            for(char c = 'a'; c <= 'z'; c++) {
                if(c == 'a') {
                    ump['a'][idx] = ump['z'][prev];
                } else if (c == 'b') {
                    ump['b'][idx] = (ump['z'][prev] + ump['a'][prev]) % modulo;
                } else {
                    ump[c][idx] = ump[c - 1][prev];
                }
            }
        }
        int ans = 0;
        for(auto x : ump) ans = (ans + x.second[idx]) % modulo;
        return ans;
    }
};
