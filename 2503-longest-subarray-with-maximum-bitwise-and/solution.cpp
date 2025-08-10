class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 1, now = 0, maxNum = *max_element(nums.begin(), nums.end());
        nums.push_back(-1);
        for(auto x : nums) {
            if(x == maxNum) now++;
            else {
                ans = max(ans, now);
                now = 0;
            }
        }
        return ans;
    }
};
