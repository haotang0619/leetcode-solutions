class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int res = 0, mx = 0, n = nums.size();
        for(auto& num : nums) res ^= num, mx = max(mx, num);
        if(res > 0) return n;
        return (mx == 0) ? 0 : (n - 1);
    }
};
