class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i = 0; i < s.length(); i++) {
            if(s == goal) return true;
            s = s.substr(1, s.length() - 1) + s[0];
        }
        return false;
    }
};
