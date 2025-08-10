class Solution {
public:
    bool hasMatch(string s, string p) {
        string s1, s2;
        bool flag = false;
        for(auto c : p) {
            if(c == '*') flag = true;
            else if(!flag) s1 += c;
            else s2 += c;
        }
        int j = -1;
        for(int i = 0; i < s.size() - (s1.size() - 1); i++) {
            if(s.substr(i, s1.size()) == s1) {
                j = i + s1.size();
                break;
            }
        }
        if(j == -1) return false;
        for(int i = j; i < s.size() - (s2.size() - 1); i++) {
            if(s.substr(i, s2.size()) == s2) return true;
        }
        return false;
    }
};
