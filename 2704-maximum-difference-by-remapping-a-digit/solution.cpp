class Solution {
public:
    void replace_all(string &s, char from, char to) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == from) s[i] = to;
        }
    }
    
    int minMaxDifference(int num) {
        string s1 = to_string(num), s2 = to_string(num);
        for(int i = 0; i < s1.size(); i++) {
            if(s2[i] != '9') {
                replace_all(s1, s1[i], '9');
                break;
            }
        }
        int a = stoi(s1);
        replace_all(s2, s2[0], '0');
        int b = stoi(s2);
        return a - b;
    }
};
