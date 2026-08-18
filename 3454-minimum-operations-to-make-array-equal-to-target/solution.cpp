class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long ans = 0;
        int prev = 0, n = nums.size();
        for(int i = 0; i <= n; i++) {
            int x = (i == n) ? 0 : (target[i] - nums[i]);
            ans += max(x - prev, 0);
            prev = x;
        }
        return ans;
    }
};
