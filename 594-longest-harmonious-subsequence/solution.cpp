class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int r = 0, ans = 0;
        for(int l = 0; l < nums.size(); l++) {
            while(r < nums.size() && nums[r] <= nums[l] + 1) r++;
            if(r > l && nums[r - 1] - nums[l] == 1) ans = max(ans, r - l);
            if(r >= nums.size()) break;
        }
        return ans;
    }
};
