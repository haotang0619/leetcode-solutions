class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> ump;
        for(auto x : words) {
            if(ump.find(x) == ump.end()) ump[x] = 0;
            ump[x]++;
        }
        set<string> st;
        bool flag = false;
        int ans = 0;
        for(auto x : ump) {
            string s = x.first;
            if(st.find(s) != st.end()) continue;
            int cnt = x.second;
            if(s[0] == s[1]) {
                if(cnt >= 2) ans += (cnt - cnt % 2) * 2;
                if(cnt % 2 == 1 && !flag) {
                    flag = true;
                    ans += 2;
                }
                st.insert(s);
            } else {
                string rev = "";
                rev += s[1];
                rev += s[0];
                if(ump.find(rev) != ump.end()) {
                    ans += min(ump[s], ump[rev]) * 4;
                    st.insert(rev);
                }
            }
        }
        return ans;
    }
};
