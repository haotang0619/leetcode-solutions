class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int prev = -1;
            bool isValid = true;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(nums[j] <= prev) {
                    isValid = false;
                    break;
                }
                prev = nums[j];
            }
            if(isValid) return true;
        }
        return false;
    }
};
