class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sk;
        for(auto c : s) {
            if(!sk.empty() && sk.top() == c) sk.pop();
            else sk.push(c);
        }
        string ans;
        while(!sk.empty()) {
            ans += sk.top();
            sk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
