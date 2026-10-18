class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int ans = 0, n = nums.size(), prev = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == prev) ans++;
            prev = nums[i];
        }
        return ans;
    }
};
