class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = 0;
        bool flag = false;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i) {
                if(!flag) {
                    flag = true;
                    ans = nums[i];
                } else ans &= nums[i];
            }
        }
        return ans;
    }
};
