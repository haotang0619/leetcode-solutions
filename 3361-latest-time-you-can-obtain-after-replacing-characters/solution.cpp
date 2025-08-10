class Solution {
public:
    string findLatestTime(string s) {
        for(int i = 0; i < 5; i++) {
            if(s[i] != '?') continue;
            if(i == 0) {
                if(s[1] == '?' || s[1] == '0' || s[1] == '1') s[0] = '1';
                else s[0] = '0';
            } else if(i == 1) {
                if(s[0] == '1') s[1] = '1';
                else s[1] = '9';
            } else if(i == 3) s[3] = '5';
            else if(i == 4) s[4] = '9';
        }
        return s;
    }
};
