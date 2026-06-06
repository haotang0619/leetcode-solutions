class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> pSum(n, 0), sSum(n, 0), ans(n, 0);
        for(int i = 1; i < n; i++) {
            pSum[i] = nums[i - 1] + (i >= 2 ? pSum[i - 1] : 0);
        }
        for(int i = n - 2; i >= 0; i--) {
            sSum[i] = nums[i + 1] + (i <= n - 3 ? sSum[i + 1] : 0);
        }
        for(int i = 0; i < n; i++) ans[i] = abs(pSum[i] - sSum[i]);
        return ans;
    }
};
