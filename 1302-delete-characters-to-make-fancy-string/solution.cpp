class Solution {
public:
    string makeFancyString(string s) {
        char curr = '\0';
        string ans;
        int cnt = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != curr) {
                curr = s[i];
                cnt = 1;
                ans += s[i];
            } else {
                cnt++;
                if(cnt < 3) ans += s[i];
            }
        }
        return ans;
    }
};
