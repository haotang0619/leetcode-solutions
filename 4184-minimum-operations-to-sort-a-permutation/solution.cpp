class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), dir = 0, idx = -1;
        if(n == 1) return 0;
        for(int i = 0; i < n; i++) {
            if(i < n - 1) {
                int rawDiff = nums[i + 1] - nums[i], diff = abs(rawDiff);
                if(diff != 1 && diff != n - 1) return -1;
                if(diff == 1) dir = rawDiff > 0 ? 0 : 1;
                else dir = rawDiff > 0 ? 1 : 0;
            }
            if(dir == 0 && nums[i] == 0) idx = i;
            if(dir == 1 && nums[i] == n - 1) idx = i;
        }
        
        int ans = INT_MAX;
        if(dir == 0) {
            // 1. dir = 0, rotate only
            ans = min(ans, idx);
            // 2. dir = 0, revert + rotate + revert
            if(idx > 0) ans = min(ans, 2 + n - idx);
        } else {
            // 3. dir = 1, rotate + revert
            ans = min(ans, idx + 1);
            // 4. dir = 1, revert + rotate
            ans = min(ans, 1 + n - idx);
        }
        return ans;
    }
};
