class Solution {
public:
    // Difference array learned
    int minMoves(vector<int>& nums, int limit) {
        int maxSum = limit * 2, n = nums.size();
        vector<int> diffs(maxSum + 2, 0);
        for(int i = 0; i < n / 2; i++) {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);
            // 2 modifications
            diffs[2] += 2;
            diffs[maxSum + 1] -= 2;
            // 1 modification
            diffs[1 + a] -= 1;
            diffs[b + limit + 1] += 1;
            // 0 modifications
            diffs[a + b] -= 1;
            diffs[a + b + 1] += 1;
        }
        int ans = INT_MAX, sum = 0;
        for(int i = 2; i <= maxSum; i++) {
            sum += diffs[i];
            ans = min(ans, sum);
        }
        return ans;
    }
};
