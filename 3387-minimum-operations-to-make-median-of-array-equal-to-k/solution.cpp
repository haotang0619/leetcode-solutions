class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size(), mid = n / 2;
        if(nums[mid] == k) return ans;
        if(nums[mid] > k) {
            for(int i = mid; i >= 0; i--) {
                if(nums[i] <= k) break;
                ans += nums[i] - k;
            }
        } else {
            for(int i = mid; i < n; i++) {
                if(nums[i] >= k) break;
                ans += k - nums[i];
            }
        }
        return ans;
    }
};
