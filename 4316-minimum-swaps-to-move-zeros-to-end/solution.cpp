class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int ans = 0, cnt = 0, n = nums.size();
        for(auto x : nums) {
            if(x == 0) cnt++;
        }
        for(int i = n - 1; i > n - 1 - cnt; i--) {
            if(nums[i] != 0) ans++;
        }
        return ans;
    }
};
