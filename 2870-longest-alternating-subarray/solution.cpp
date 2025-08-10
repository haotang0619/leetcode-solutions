class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = -1;
        for(int i = 0; i < nums.size(); i++) {
            int now = nums[i] + 1, len = 1;
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] == now) {
                    len++;
                    now = nums[j - 1];
                } else break;
            }
            if(len > 1) ans = max(ans, len);
        }
        return ans;
    }
};
