class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i += 2) nums[i] = -nums[i];
        long long orig = accumulate(nums.begin(), nums.end(), 0LL);
        
        vector<long long> pSum(n + 1, 0);
        for(int i = 1; i <= n; i++) pSum[i] = pSum[i - 1] - nums[i - 1] * 2;
        long long mx = 0, mn1 = pSum[0], mn2 = pSum[1];
        for(int i = 2; i <= n; i++) {
            if(i % 2 == 0) mn1 = min(mn1, pSum[i - 2]);
            else mn2 = min(mn2, pSum[i - 2]);
            
            if(i % 2 == 0) mx = max(mx, pSum[i] - mn1);
            else mx = max(mx, pSum[i] - mn2);
        }
        return orig + mx;
    }
};
