class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int tar = nums[n / 2];
        for(int i = 0; i < n; i++) {
            if(i == n / 2) continue;
            if(nums[i] == tar) return false;
        }
        return true;
    }
};
