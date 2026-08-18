class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(ans.size() >= k) break;
            if(ans.empty() || ans.back() != nums[i]) ans.push_back(nums[i]);
        }
        return ans;
    }
};
