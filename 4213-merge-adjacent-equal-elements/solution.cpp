class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> sk;
        for(auto& num : nums) {
            long long now = num;
            while(!sk.empty() && sk.top() == now) {
                sk.pop();
                now *= 2;
            }
            sk.push(now);
        }
        vector<long long> ans;
        while(!sk.empty()) ans.push_back(sk.top()), sk.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
