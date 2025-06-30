class Solution {
public:
    int modulo = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        vector<int> pow_of_2(nums.size() + 1, 1);
        for(int i = 1; i <= nums.size(); i++) {
            pow_of_2[i] = (pow_of_2[i - 1] * 2) % modulo;
        }

        sort(nums.begin(), nums.end());
        int ans = 0, r = nums.size() - 1;
        for(int l = 0; l < nums.size(); l++) {
            while(r >= l && nums[l] + nums[r] > target) r--;
            if(r >= l) {
                ans = (ans + pow_of_2[r - l]) % modulo;
            } else break;
        }
        return ans;
    }
};
