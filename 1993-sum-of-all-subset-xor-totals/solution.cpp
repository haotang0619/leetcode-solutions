class Solution {
public:
    void solve(vector<int>& nums, int& ans, int& curr, int idx) {
        ans += curr;
        for(int i = idx; i < nums.size(); i++) {
            curr ^= nums[i];
            solve(nums, ans, curr, i + 1);
            curr ^= nums[i];
        }
    }

    int subsetXORSum(vector<int>& nums) {
        int ans = 0, curr = 0;
        solve(nums, ans, curr, 0);
        return ans;
    }
};
