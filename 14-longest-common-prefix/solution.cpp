class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int i = 0;
        while(true) {
            char now = '\0';
            for(auto &s : strs) {
                if(s.size() <= i) return ans;
                if(now == '\0') now = s[i];
                else if(now != s[i]) return ans;
            }
            ans += now;
            i++;
        }
    }
};
