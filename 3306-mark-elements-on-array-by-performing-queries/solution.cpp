class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) v[i] = {nums[i], i};
        sort(v.begin(), v.end());
        int idx = 0;
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        vector<bool> mark(n, false);
        vector<long long> ans;
        for(auto& q : queries) {
            int i = q[0], k = q[1];
            if(!mark[i]) sum -= nums[i], mark[i] = true;
            int cnt = 0;
            while(idx < n && cnt < k) {
                int j = v[idx].second;
                if(!mark[j]) {
                     sum -= nums[j], mark[j] = true, cnt++;
                }
                idx++;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
