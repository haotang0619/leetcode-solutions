class Solution {
public:
    using ull = unsigned long long;

    bool isInt(double d) {
        return (int)d == d;
    }

    string buildAns(string& s, double center) {
        string ans;
        for(int i = s.size() - 1; (double)i >= center; i--) ans += s[i];
        for(int i = (int)center + 1; i < s.size(); i++) ans += s[i];
        return ans;
    }

    int charToInt(char c) {
        return c - 'a' + 1;
    }

    string shortestPalindrome(string s) {
        int n = s.size(), base = 131;
        ull lHash = 0, rHash = 0;
        double init = (double)(n - 1) / 2;
        int l = isInt(init) ? (int)init - 1 : (int)(init - 0.5);
        int r = isInt(init) ? (int)init + 1 : (int)(init + 0.5);
        while(l >= 0) {
            lHash = lHash * base + charToInt(s[l--]);
            rHash = rHash * base + charToInt(s[r++]);
        }
        vector<ull> powers(n, 1);
        for(int i = 1; i < n; i++) powers[i] = powers[i - 1] * base;
        int rPow = 0;
        for(double center = init; center > 0; center -= 0.5) {
            if(lHash * powers[rPow] == rHash) return buildAns(s, center);
            if(isInt(center)) {
                rHash -= charToInt(s[center * 2]) * powers[rPow];
                rHash += charToInt(s[center]) * powers[center + rPow];
                rPow++;
            } else {
                lHash -= charToInt(s[center - 0.5]) * powers[center - 0.5];
                rHash -= charToInt(s[center * 2]) * powers[rPow];
                rPow++;
            }
        }
        return buildAns(s, 0);
    }
};
