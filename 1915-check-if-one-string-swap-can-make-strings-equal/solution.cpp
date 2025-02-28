class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int len = s1.length();
        vector<int> v;

        for(int i = 0; i < len; i++) {
            if(s1[i] != s2[i]) v.push_back(i);
            if(v.size() > 2) return false;
        }
        if(v.size() == 1) return false;
        if(v.size() == 0) return true;
        return s1[v[0]] == s2[v[1]] && s1[v[1]] == s2[v[0]];
    }
};
