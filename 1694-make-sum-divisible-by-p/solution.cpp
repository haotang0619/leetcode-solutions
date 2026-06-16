class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<long long> pSum(n + 1, 0);
        for(int i = 1; i <= n; i++) pSum[i] = pSum[i - 1] + nums[i - 1];
        if(pSum[n] % p == 0) return 0;
        int ans = INT_MAX, diff = pSum[n] % p;
        unordered_map<int, int> mp;
        for(int i = 0; i <= n; i++) {
            int rem = pSum[i] % p, prev = (rem - diff + p) % p;
            if(mp.contains(prev)) {
                int now = i - mp[prev];
                if(now < n) ans = min(ans, now);
            }
            mp[rem] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
