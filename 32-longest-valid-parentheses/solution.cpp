class Solution {
public:
    int longestValidParentheses(string s) {
        stack<string> sk;
        int ans = 0, left = 0;
        for(auto x : s) {
            if(x == '(') {
                sk.push("(");
                left++;
            } else {
                int cnt = 0;
                if(left > 0 && !sk.empty() && sk.top() != ")") {
                    bool flag = false;
                    while(!sk.empty() && sk.top() != ")") {
                        if(sk.top() == "(") {
                            if(flag) break;
                            left--;
                            cnt += 2;
                            flag = true;
                        } else cnt += stoi(sk.top());
                        sk.pop();
                    }
                    ans = max(ans, cnt);
                    sk.push(to_string(cnt));
                } else sk.push(")");
            }
        }
        return ans;
    }
};
