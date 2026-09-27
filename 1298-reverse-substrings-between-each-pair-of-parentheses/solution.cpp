class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> sk;
        string ans;
        for(auto& c : s) {
            if(c == '(') sk.push("(");
            else if(c == ')') {
                string tmp;
                while(sk.top() !=  "(") {
                    string top = sk.top();
                    reverse(top.begin(), top.end());
                    tmp += top, sk.pop();
                }
                sk.pop();
                if(sk.empty()) ans += tmp;
                else sk.push(tmp);
            } else if(sk.empty()) ans += c;
            else sk.push({c});
        }
        return ans;
    }
};
