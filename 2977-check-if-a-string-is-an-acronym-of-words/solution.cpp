class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string s1;
        for(auto& w : words) s1 += w[0];
        return s == s1;
    }
};
