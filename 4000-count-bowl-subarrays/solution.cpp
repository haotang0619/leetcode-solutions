class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long ans = 0, n = nums.size();
        stack<pair<int, int>> sk; // [idx, val]
        for(int r = 0; r < n; r++) {
            while(!sk.empty() && sk.top().second < nums[r]) {
                sk.pop();
                if(!sk.empty()) {
                    auto& [l, _] = sk.top();
                    if(r - l + 1 >= 3) ans++;
                }
            }
            sk.push({r, nums[r]});
        }
        return ans;
    }
};
