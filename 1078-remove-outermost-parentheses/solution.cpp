class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> sk;
        string ans;
        for(auto& c : s) {
            if(sk.empty()) sk.push(c);
            else {
                if(c == '(') ans += c, sk.push(c);
                else {
                    sk.pop();
                    if(!sk.empty()) ans += c;
                }
            }
        }
        return ans;
    }
};
