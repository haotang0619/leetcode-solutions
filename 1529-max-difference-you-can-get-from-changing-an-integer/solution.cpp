class Solution {
public:
    void replace_all(string &s, char from, char to) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == from) s[i] = to;
        }
    }

    int maxDiff(int num) {
        string s1 = to_string(num), s2 = to_string(num);
        for(int i = 0; i < s1.size(); i++) {
            if(s2[i] != '9') {
                replace_all(s1, s1[i], '9');
                break;
            }
        }
        int a = stoi(s1);
        if(s2[0] != '1') replace_all(s2, s2[0], '1');
        else {
            for(int i = 1; i < s2.size(); i++) {
                if(s2[i] != '1' && s2[i] != '0') {
                    replace_all(s2, s2[i], '0');
                    break;
                }
            }
        }
        int b = stoi(s2);
        return a - b;
    }
};
