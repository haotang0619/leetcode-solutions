class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i += 3) {
            if(nums[i + 2] - nums[i] > k) return (vector<vector<int>>){};
            else ans.push_back(vector<int>(nums.begin() + i, nums.begin() + i + 3));
        }
        return ans;
    }
};
