class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sk;
        for(auto x : tokens) {
            if(x == "+" || x == "-" || x == "*" || x == "/") {
                int ans;
                int b = sk.top();
                sk.pop();
                int a = sk.top();
                sk.pop();
                if(x == "+") ans = a + b;
                else if(x == "-") ans = a - b;
                else if(x == "*") ans = a * b;
                else ans = a / b;
                sk.push(ans);
            } else sk.push(stoi(x));
        }
        return sk.top();
    }
};
