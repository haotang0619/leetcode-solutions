class Solution {
public:
    using ull = unsigned long long;

    int charToInt(char c) {
        return c - 'a' + 1;
    }

    string longestPrefix(string s) {
        int base = 131, n = s.size();
        ull h1 = 0, h2 = 0, p = 1;
        int len = 0;
        for(int i = 0; i < n - 1; i++) {
            int j = n - 1 - i;
            h1 = h1 * base + charToInt(s[i]);
            h2 = h2 + charToInt(s[j]) * p;
            if(h1 == h2) len = i + 1;
            p *= base;
        }
        string ans;
        for(int i = 0; i < len; i++) ans += s[i];
        return ans;
    }
};
