class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int ans = s.size();
        stack<char> sk;
        for(auto& c : s) {
            if(!sk.empty() && sk.top() != c) ans -= 2, sk.pop();
            else sk.push(c);
        }
        return ans;
    }
};
