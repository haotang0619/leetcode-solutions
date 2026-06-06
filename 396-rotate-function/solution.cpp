class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), now = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            now += nums[i] * i;
            sum += nums[i];
        }
        int ans = now;
        for(int i = n - 1; i >= 1; i--) {
            now -= (n - 1) * nums[i];
            now += (sum - nums[i]);
            ans = max(ans, now);
        }
        return ans;
    }
};
