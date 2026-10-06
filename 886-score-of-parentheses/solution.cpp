class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> sk;
        sk.push(0);
        for(auto& c : s) {
            if(c == '(') sk.push(0);
            else {
                int top = sk.top();
                sk.pop();
                int score = (top == 0) ? 1 : (top * 2);
                sk.top() += score;
            }
        }
        return sk.top();
    }
};
