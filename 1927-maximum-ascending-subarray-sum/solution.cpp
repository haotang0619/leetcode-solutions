class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = -1;
        int curr = nums[0];
        int prev = INT_MAX;
        for (int n : nums) {
            if(n <= prev) {
                ans = max(ans, curr);
                curr = n;
            } else curr += n;
            prev = n;
        }
        ans = max(ans, curr);
        return ans;
    }
};
