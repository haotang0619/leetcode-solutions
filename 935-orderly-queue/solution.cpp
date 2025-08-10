class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k >= 2) {
            sort(s.begin(), s.end());
            return s;
        }
        string ans = s;
        for(int i = 1; i < s.size(); i++) {
            string s1 = s.substr(i) + s.substr(0, i);
            ans = min(ans, s1);
        }
        return ans;
    }
};
