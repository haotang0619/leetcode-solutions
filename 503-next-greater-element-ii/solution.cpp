class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<pair<int, int>> sk;
        for(int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            while(!sk.empty() && sk.top().first < nums[idx]) {
                auto [num, j] = sk.top();
                if(j < n) ans[j] = nums[idx];
                sk.pop();
            }
            sk.push({nums[idx], i});
        }
        return ans;
    }
};
