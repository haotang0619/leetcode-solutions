class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] == 1 && nums[j] == 2 || nums[i] == 2 && nums[j] == 1) {
                    ans = min(ans, j - i);
                }
            }
        }
        return ans == (n + 1) ? -1 : ans;
    }
};
