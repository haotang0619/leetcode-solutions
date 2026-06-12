class Solution {
public:
    void findAns(int &ans, int idx, vector<int>& nums, int now, int target) {
        if(idx == nums.size()) {
            if(now == target) ans++;
            return;
        }
        findAns(ans, idx + 1, nums, now + nums[idx], target);
        findAns(ans, idx + 1, nums, now - nums[idx], target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        findAns(ans, 0, nums, 0, target);
        return ans;
    }
};
