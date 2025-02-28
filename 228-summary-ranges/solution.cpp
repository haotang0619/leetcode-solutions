class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return {};
        if(nums.size() == 1) return {to_string(nums[0])};
        vector<string> ans;
        int left = nums[0];
        for(int i = 1; i <= nums.size(); i++) {
            if(i == nums.size() || nums[i] != nums[i - 1] + 1) {
                int right = nums[i - 1];
                ans.push_back(left == right ? to_string(left) : format("{}->{}", left, right));
                if(i < nums.size()) left = nums[i];
            }
        }
        return ans;
    }
};
