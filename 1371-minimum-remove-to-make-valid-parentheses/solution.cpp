class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<bool> v(n, true);
        stack<int> sk;
        for(int i = 0; i < n; i++) {
            if(s[i] == ')') {
                if(sk.empty()) v[i] = false;
                else sk.pop();
            } else if(s[i] == '(') sk.push(i);
        }
        while(!sk.empty()) {
            v[sk.top()] = false;
            sk.pop();
        }
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(v[i]) ans += s[i];
        }
        return ans;
    }
};
