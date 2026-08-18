class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0, j = 0; j < n; j++) {
            int prev = (j == 0) ? -1 : nums[j - 1];
            if(prev == nums[j]) i = j;
            ans += j - i + 1;
        }
        return ans;
    }
};
