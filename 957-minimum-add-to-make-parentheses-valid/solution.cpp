class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        stack<char> sk;
        for(auto c : s) {
            if(c == '(') sk.push(c);
            else {
                if(sk.empty()) ans++;
                else sk.pop();
            }
        }
        return ans + sk.size();
    }
};
