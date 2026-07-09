// Saw a solution
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> lens(n);
        long long len = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] >= 'a' && s[i] <= 'z') len++;
            else if(s[i] == '#') len *= 2;
            else if(s[i] == '*') len = max(len - 1, 0LL);
            lens[i] = len;
        }
        if(k >= len) return '.';
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '%') k = lens[i] - 1 - k;
            if(s[i] == '#') k = k % (lens[i] / 2);
            if(s[i] >= 'a' && s[i] <= 'z' && k + 1 == lens[i]) return s[i];
        }
        return '.';
    }
};
