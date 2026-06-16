class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int ans = 0, acc = 0, now = 0, prev = 0, n = nums.size(), minN = nums[n - 1];
        for(int i = 0; i < n; i++) {
            if(nums[i] != prev) {
                acc += now;
                ans += acc;
                now = 0;
            }
            if(nums[i] == minN) break;
            now++, prev = nums[i];
        }
        return ans;
    }
};
