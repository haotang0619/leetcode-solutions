class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        string s1, s2;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                s1 += s.substr(i);
                break;
            } else if(s[i] != ')') s1 += s[i];
        }
        reverse(s1.begin(), s1.end());
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] == ')') {
                s2 += s1.substr(i);
                break;
            } else if(s1[i] != '(') s2 += s1[i];
        }
        reverse(s2.begin(), s2.end());
        s = s2;

        int cnt = 0;
        stack<char> sk;
        for(auto& c : s) {
            if(c == '(') sk.push(c);
            else if(c == ')') {
                if(!sk.empty()) sk.pop(), cnt++;
            }
        }
        
        unordered_set<string> st;
        auto build = [&](auto&& self, string now, int cnt1, int cnt2, int idx) {
            if(idx == s.size()) {
                if(cnt == cnt1 && cnt == cnt2) st.insert(now);
                return;
            }
            auto& c = s[idx];
            if(c == '(' || c == ')') self(self, now, cnt1, cnt2, idx + 1);
            if(c == '(') cnt1++;
            else if(c == ')') cnt2++;
            if(cnt1 <= cnt && cnt2 <= cnt) self(self, now + c, cnt1, cnt2, idx + 1);
        };
        build(build, "", 0, 0, 0);

        auto check = [](string tmp) {
            stack<char> sk;
            for(auto& c : tmp) {
                if(c == '(') sk.push(c);
                else if(c == ')') {
                    if(!sk.empty()) sk.pop();
                    else return false;
                }
            }
            return sk.empty();
        };
        for(auto it = st.begin(); it != st.end();) {
            if(!check(*it)) st.erase(it++);
            else it++;
        }
        if(st.empty()) st.insert("");
        
        return vector<string>(st.begin(), st.end());
    }
};
