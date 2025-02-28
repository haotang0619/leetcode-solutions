class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int ans = 1e6;
        for(int i = 0; i < len; i++) {
            for(int j = i + 1; j < len; j++) {
                for(int k = j + 1; k < len; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    ans = abs(sum - target) < abs(ans - target) ? sum : ans;
                }
            }
        }
        
        return ans;
    }
};
