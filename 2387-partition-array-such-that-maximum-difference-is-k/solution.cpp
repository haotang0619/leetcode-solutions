class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, min_now = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > min_now + k) {
                ans++;
                min_now = nums[i];
            }
        }
        return ans;
    }
};
