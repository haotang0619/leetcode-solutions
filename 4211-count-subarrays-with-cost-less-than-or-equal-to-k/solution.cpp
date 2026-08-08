class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<pair<int, int>> dqmn, dqmx;
        long long ans = 0;
        int n = nums.size();
        for(int l = 0, r = 0; l < n; l++) {
            while(r < n) {
                while(!dqmn.empty() && dqmn.back().second >= nums[r]) dqmn.pop_back();
                while(!dqmx.empty() && dqmx.back().second <= nums[r]) dqmx.pop_back();
                dqmn.push_back({r, nums[r]}), dqmx.push_back({r, nums[r]});
                int mn = dqmn.front().second, mx = dqmx.front().second;
                long long cost = (long long)(mx - mn) * (r - l + 1);
                if(cost > k) break;
                r++;
            }
            ans += r - l;
            while(!dqmn.empty() && dqmn.front().first <= l) dqmn.pop_front();
            while(!dqmx.empty() && dqmx.front().first <= l) dqmx.pop_front();
        }
        return ans;
    }
};
