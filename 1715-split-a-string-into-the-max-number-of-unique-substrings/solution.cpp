class Solution {
public:
    void findAns(int& ans, unordered_set<string>& st, int idx, string& s) {
        if(idx == s.length()) {
            ans = max(ans, (int)st.size());
            return;
        }

        if((int)st.size() + s.length() - idx <= ans) return;
        for(int i = 1; i <= s.length() - idx; i++) {
            string s1 = s.substr(idx, i);
            if(st.find(s1) == st.end()) {
                st.insert(s1);
                findAns(ans, st, idx + i, s);
                st.erase(s1);
            }
        }
    }

    int maxUniqueSplit(string s) {
        int ans = 1;
        unordered_set<string> st;
        findAns(ans, st, 0, s);
        return ans;
    }
};
