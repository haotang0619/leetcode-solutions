class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int t = nums[i];
            while(t >= 1 && t <= n) {
                if(nums[t - 1] == t) break;
                swap(nums[i], nums[t - 1]);
                t = nums[i];
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
