class Solution {
public:
    void findAns(vector<int>& nums, int idx, int curr, int target, int& ans) {
        if(idx == nums.size()) {
            if(curr == target) ans++;
            return;
        }
        findAns(nums, idx + 1, curr | nums[idx], target, ans);
        findAns(nums, idx + 1, curr, target, ans);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for(auto x : nums) target |= x;
        int ans = 0;
        findAns(nums, 0, 0, target, ans);
        return ans;
    }
};
