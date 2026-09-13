class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string s1odd, s1even, s2odd, s2even;
        int n = s1.size();
        for(int i = 0; i < n; i++) {
            if(i & 1) s1odd += s1[i], s2odd += s2[i];
            else s1even += s1[i], s2even += s2[i];
        }
        sort(s1odd.begin(), s1odd.end());
        sort(s1even.begin(), s1even.end());
        sort(s2odd.begin(), s2odd.end());
        sort(s2even.begin(), s2even.end());
        return (s1odd == s2odd) && (s1even == s2even);
    }
};
