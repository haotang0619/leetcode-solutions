class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int prev = INT_MIN;
        for(int n : nums) {
            if(n < prev) cnt++;
            if(cnt >= 2) return false;
            prev = n;
        }
        if(cnt == 0) return true;
        return nums[nums.size() - 1] <= nums[0];
    }
};
