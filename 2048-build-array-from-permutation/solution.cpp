class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(auto x : nums) ans.push_back(nums[x]);
        return ans;
    }
};
