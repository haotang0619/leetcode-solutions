class Solution {
public:
    string longestPalindrome(string s) {
        string s1 = "*";
        for(auto& c : s) s1 += c, s1 += '*';
        int n = s1.size(), maxLen = -1, idx = -1;
        for(int i = 0; i < n; i++) {
            for(int j = i, k = i; j >= 0 && k < n; j--, k++) {
                if(s1[j] != s1[k]) break;
                int len = k - i;
                if(maxLen < len) maxLen = len, idx = i;
            }
        }
        string center, s2;
        if(s1[idx] != '*') center += s1[idx];
        for(int i = idx + 1; i <= idx + maxLen; i++) {
            if(s1[i] != '*') s2 += s1[i];
        }
        string s3 = s2;
        reverse(s3.begin(), s3.end());
        return s3 + center + s2;
    }
};
