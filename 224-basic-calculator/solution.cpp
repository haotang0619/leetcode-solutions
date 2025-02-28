class Solution {
public:
    int calculate(string s) {
        stack<char> sk;
        vector<string> rpn;
        string curr = "";
        bool flag = false;
        for(int i = 0; i < s.length(); i++) {
            char x = s[i];
            if(s[i] < '0' || s[i] > '9') {
                if(curr != "") {
                    rpn.push_back(curr);
                    flag = true;
                }
                curr = "";
            }

            if(x == ' ') continue;
            if (x == '+' || x == '-') {
                while(!sk.empty() && sk.top() != '(') {
                    rpn.push_back(string{sk.top()});
                    sk.pop();
                }
                sk.push(x == '-' && !flag ? '_' : x);
            } else if(x == '(') {
                flag = false;
                sk.push(x);
            } else if(x == ')') {
                while(sk.top() != '(') {
                    rpn.push_back(string{sk.top()});
                    sk.pop();
                }
                sk.pop();
            } else curr.push_back(x);
        }
        if(curr != "") rpn.push_back(curr);
        while(!sk.empty()) {
            rpn.push_back(string{sk.top()});
            sk.pop();
        }
        
        stack<int> sk2;
        for(auto x : rpn) cout << x << " ";
        for(auto x : rpn) {
            if(x == "+" || x == "-") {
                int b = sk2.top();
                sk2.pop();
                int a = sk2.top();
                sk2.pop();
                sk2.push(x == "+" ? a + b : a - b);
            } else if(x == "_") {
                int b = sk2.top();
                sk2.pop();
                sk2.push(-b);
            }
            else sk2.push(stoi(x));
        }
        return sk2.top();
    }
};
