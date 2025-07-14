class Solution {
public:
    int possibleStringCount(string word) {
        char prev = '\0';
        word += '0';
        int cnt = 0, now = 1, ans = 1;
        for(auto x : word) {
            if(x == prev) now++;
            else {
                if(now > 1) {
                    ans += now;
                    cnt++;
                }
                now = 1;
                prev = x;
            }
        }
        return ans - cnt;
    }
};
