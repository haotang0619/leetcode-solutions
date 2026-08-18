class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 2, n = s.size();
        vector<int> cnts(26, 0);
        for(int i = 0, j = 0; j < n; j++) {
            ++cnts[s[j] - 'a'];
            while(cnts[s[j] - 'a'] > 2) --cnts[s[i++] - 'a'];
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
