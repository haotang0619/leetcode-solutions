class Solution {
public:
    int mod = 1e9 + 7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> diffArr(n + 1, 0);
        for(auto &req : requests) {
            int l = req[0], r = req[1];
            diffArr[l]++, diffArr[r + 1]--;
        }
        vector<int> pSum(n, 0);
        for(int i = 0; i < n; i++) pSum[i] = diffArr[i] + (i > 0 ? pSum[i - 1] : 0);
        sort(nums.begin(), nums.end());
        sort(pSum.begin(), pSum.end());
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans = (ans + (long long)pSum[i] * nums[i]) % mod;
        }
        return ans;
    }
};
