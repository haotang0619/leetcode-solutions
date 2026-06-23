class Solution {
public:
    string decodeString(string s) {
        int k = 0, n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(s[i] >= '0' && s[i] <= '9') k = k * 10 + (s[i] - '0');
            else if(s[i] == '[') {
                string subs = "";
                int cnt = 1, j = i + 1;
                while(cnt > 0) {
                    if(s[j] == '[') cnt++;
                    else if(s[j] == ']') cnt--;
                    if(cnt > 0) subs += s[j];
                    j++;
                }
                string res = decodeString(subs);
                for(int x = 0; x < k; x++) ans += res;
                k = 0;
                i = j - 1;
            } else ans += s[i];
        }
        return ans;
    }
};
