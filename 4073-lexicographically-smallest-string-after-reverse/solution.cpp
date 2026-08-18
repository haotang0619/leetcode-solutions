class Solution {
public:
    string lexSmallest(string s) {
        string ans;
        int n = s.size();
        for(int k = 1; k <= n; k++) {
            string s1 = s, s2 = s;
            reverse(s1.begin(), s1.begin() + k);
            reverse(s2.end() - k, s2.end());
            if(ans == "") ans = s1;
            ans = min({ans, s1, s2});
        }
        return ans;
    }
};
