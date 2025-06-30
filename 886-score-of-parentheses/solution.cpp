class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> sk;
        for(auto x : s) {
            if(x == '(') {
                sk.push(string({x}));
            } else {
                int now = 0;
                while(sk.top() != "(") {
                    now += stoi(sk.top());
                    sk.pop();
                }
                if(now == 0) now = 1;
                else now *= 2;
                sk.pop();
                sk.push(to_string(now));
            }
        }
        int ans = 0;
        while(!sk.empty()) {
            ans += stoi(sk.top());
            sk.pop();
        }
        return ans;
    }
};
