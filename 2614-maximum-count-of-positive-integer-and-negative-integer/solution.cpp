class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto x = upper_bound(nums.begin(), nums.end(), -1);
        auto y = upper_bound(nums.begin(), nums.end(), 0);
        int ncnt = x - nums.begin(), pcnt = nums.end() - y;
        return max(ncnt, pcnt);
    }
};
