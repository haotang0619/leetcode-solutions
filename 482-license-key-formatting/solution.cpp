class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.size();
        string ans;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '-') continue;
            if(s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
            if(ans.size() > 0 && (ans.size() + 1) % (k + 1) == 0) ans += '-';
            ans += s[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
