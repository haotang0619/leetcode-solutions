class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        long long ans = 0, cnt = 0;
        stack<pair<int, int>> sk;
        for(auto& x : nums) {
            while(!sk.empty() && sk.top().first > x) {
                cnt -= sk.top().second, sk.pop();
            }
            if(!sk.empty() && sk.top().first == x) sk.top().second++; 
            else sk.push({x, 1});
            cnt++;
            ans += cnt - sk.top().second;
        }
        return ans;
    }
};
