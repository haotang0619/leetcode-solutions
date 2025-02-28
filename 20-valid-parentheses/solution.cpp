class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        for(auto x : s) {
            if(x == '(' || x == '{' || x == '[') sk.push(x);
            else if(x == ')') {
                if(sk.empty() || sk.top() != '(') return false;
                sk.pop();
            } else if(x == '}') {
                if(sk.empty() ||sk.top() != '{') return false;
                sk.pop();
            } else {
                if(sk.empty() ||sk.top() != '[') return false;
                sk.pop();
            }
        }
        return sk.empty();
    }
};
