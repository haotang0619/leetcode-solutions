class Solution {
public:
    int countBinarySubstrings(string s) {
        char prev = '\0';
        int ans = 0, cnt0 = 0, cnt1 = 0;
        s += '\0';
        for(auto &c : s) {
            if(prev != c) {
                ans += min(cnt0, cnt1);
                if(c == '0') cnt0 = 0;
                else cnt1 = 0;
            }
            if(c == '0') cnt0++;
            else cnt1++;
            prev = c;
        }
        return ans;
    }
};
