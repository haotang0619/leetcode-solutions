class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> costSum1(n, 0), costSum2(n, 0);
        for(int i = 1; i < n; i++) {
            costSum1[i] = costSum1[i - 1];
            if(i == 1) costSum1[i] += 1;
            else {
                if(nums[i] - nums[i - 1] < nums[i - 1] - nums[i - 2]) {
                    costSum1[i] += 1;
                } else costSum1[i] += nums[i] - nums[i - 1];
            }
        }
        for(int i = n - 2; i >= 0; i--) {
            costSum2[i] = costSum2[i + 1];
            if(i == n - 2) costSum2[i] += 1;
            else {
                if(nums[i + 1] - nums[i] <= nums[i + 2] - nums[i + 1]) {
                    costSum2[i] += 1;
                } else costSum2[i] += nums[i + 1] - nums[i];
            }
        }
        vector<int> ans;
        for(auto q : queries) {
            if(q[0] <= q[1]) {
                ans.push_back(costSum1[q[1]] - costSum1[q[0]]);
            } else {
                ans.push_back(costSum2[q[1]] - costSum2[q[0]]);
            }
        }
        return ans;
    }
};
