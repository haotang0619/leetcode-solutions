class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int t = nums[i];
            while(true) {
                if(nums[t - 1] == t) break;
                int tmp = nums[t - 1];
                nums[t - 1] = t;
                nums[i] = tmp;
                t = tmp;
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) return nums[i];
        }
        return 0;
    }
};
