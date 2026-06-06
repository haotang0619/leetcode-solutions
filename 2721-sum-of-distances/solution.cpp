class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<long long>> mp;
        for(int i = 0; i < n; i++) mp[nums[i]].push_back(i);
        vector<long long> ans(n, 0LL);
        for(auto x : mp) {
            auto v = x.second;
            int len = v.size();
            vector<long long> sum = {v[0]};
            for(int i = 1; i < len; i++) sum.push_back(sum[i - 1] + v[i]);
            for(int i = 0; i < len; i++) {
                long long prefixSum = i > 0 ? sum[i - 1] : 0;
                long long suffixSum = sum[len - 1] - sum[i];
                ans[v[i]] = (v[i] * i - prefixSum) + (suffixSum - v[i] * (len - i - 1));
            }
        }
        return ans;
    }
};
