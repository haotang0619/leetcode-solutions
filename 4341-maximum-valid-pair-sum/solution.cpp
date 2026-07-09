class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        vector<int> maxUntil(n, 0);
        maxUntil[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            maxUntil[i] = max(maxUntil[i + 1], nums[i]);
        }
        for(int i = 0; i < n - k; i++) {
            ans = max(ans, nums[i] + maxUntil[i + k]);
        }
        return ans;
    }
};
