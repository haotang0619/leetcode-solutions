class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size(), pSum = 0;
        vector<int> diff(n + 1, 0);
        for(int i = 0; i < n; i++) {
            pSum += diff[i];
            int now = nums[i] - pSum;
            if(now < 0) return false;
            if(now == 0) continue;
            if(i + k > n) return false;
            diff[i + 1] += now;
            diff[i + k] -= now;
        }
        return true;
    }
};
