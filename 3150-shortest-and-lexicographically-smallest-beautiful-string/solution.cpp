class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans;
        int cnt = 0, n = s.size();
        for(int l = 0, r = 0; r < n; r++) {
            if(s[r] == '1') cnt++;
            while(cnt == k) {
                string s1 = s.substr(l, r - l + 1);
                if(
                    ans.empty() || 
                    ans.size() > s1.size() || 
                    ans.size() == s1.size() && ans > s1
                ) ans = s1;
                if(s[l++] == '1') cnt--;
            }
        }
        return ans;
    }
};
