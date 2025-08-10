class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        stack<int> sk;
        int ans = 0;
        for(auto x : target) {
            if(sk.empty()) ans += x;
            else if(sk.top() <= x) ans += x - sk.top();
            while(!sk.empty() && sk.top() <= x) sk.pop();
            sk.push(x);
        }
        return ans;
    }
};
