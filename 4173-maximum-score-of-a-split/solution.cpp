class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> sMin(n);
        sMin[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) sMin[i] = min(sMin[i + 1], nums[i]);
        long long ans = LLONG_MIN, pSum = 0;
        for(int i = 0; i < n - 1; i++) {
            pSum += nums[i];
            ans = max(ans, pSum - sMin[i + 1]);
        }
        return ans;
    }
};
