class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int l = lower;
        for(auto& num : nums) {
            if(num < lower) continue;
            int r = min(num - 1, upper);
            if(l <= r) ans.push_back({l, r});
            l = num + 1;
        }
        if(l <= upper) ans.push_back({l, upper});
        return ans;
    }
};
