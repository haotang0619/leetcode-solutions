class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = -1, n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(((j - i) % 2 == 0 && nums[j] == nums[i]) || ((j - i) % 2 == 1 && nums[j] == nums[i] + 1)) {
                    if(j - i + 1 >= 2) ans = max(ans, j - i + 1);
                } else break;
            }
        }
        return ans;
    }
};
