class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0, n = nums.size(), i = 1;
        while(i < n - 1) {
            int j = i - 1, l = -1, r = -1;
            while(j >= 0 && nums[j] == nums[i]) j--;
            if(j >= 0) l = nums[j];
            j = i + 1;
            while(j < n && nums[j] == nums[i]) j++;
            if(j < n) r = nums[j];
            if(l > -1 && r > -1) {
                if(l < nums[i] && r < nums[i]) ans++;
                if(l > nums[i] && r > nums[i]) ans++;
            }
            i = j;
        }
        return ans;
    }
};
