class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int ans = 0, m = nums.size(), n = nums[0].size();
        for(auto& num : nums) sort(num.rbegin(), num.rend());
        for(int j = 0; j < n; j++) {
            int mx = -1;
            for(int i = 0; i < m; i++) mx = max(mx, nums[i][j]);
            ans += mx;
        }
        return ans;
    }
};
