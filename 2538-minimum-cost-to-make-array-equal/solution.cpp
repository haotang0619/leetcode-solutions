class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int& a, int& b) {
            return nums[a] < nums[b];
        });

        vector<long long> pSumCost(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            pSumCost[i] = pSumCost[i - 1] + cost[indices[i - 1]];
        }

        int idx = indices[0], val = nums[idx];
        long long ans = 0;
        for(int i = 0; i < n; i++) ans += (long long)cost[i] * abs(nums[i] - val);
        long long now = ans;
        for(int i = 1; i < n; i++) {
            int newIdx = indices[i], newVal = nums[newIdx];
            int diff = newVal - val;
            now += (pSumCost[i] - pSumCost[0]) * diff;
            now -= (pSumCost[n] - pSumCost[i]) * diff;
            ans = min(ans, now);
            val = newVal;
        }
        return ans;
    }
};
