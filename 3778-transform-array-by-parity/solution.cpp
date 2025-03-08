class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        for(auto &x : nums) {
            x = x % 2 == 1 ? 1 : 0;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};
