class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int ans = 0, n = nums.size(), m = pattern.size();
        for(int i = 0; i < n - m; i++) {
            for(int j = i; j < i + m; j++) {
                int p = pattern[j - i];
                if(nums[j + 1] > nums[j] && p != 1) break;
                if(nums[j + 1] == nums[j] && p != 0) break;
                if(nums[j + 1] < nums[j] && p != -1) break;
                if(j == i + m - 1) ans++;
            }
        }
        return ans;
    }
};
