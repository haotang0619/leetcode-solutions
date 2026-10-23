class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = 0, n = nums.size();
        bool flag = false;
        for(int i = 0; i < n; i++) {
            if(nums[i] != i) {
                if(!flag) flag = true, ans = nums[i];
                else ans &= nums[i];
            }
        }
        return ans;
    }
};
