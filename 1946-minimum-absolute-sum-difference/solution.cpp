class Solution {
public:
    int mod = 1e9 + 7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int curr = 0, n = nums1.size();
        for(int i = 0; i < n; i++) curr = (curr + abs(nums1[i] - nums2[i])) % mod;
        vector<int> nums3(nums1.begin(), nums1.end());
        sort(nums3.begin(), nums3.end());
        int max_loss = 0;
        for(int i = 0; i < n; i++) {
            int target = nums2[i];
            int low_idx = lower_bound(nums3.begin(), nums3.end(), target) - nums3.begin();
            if(low_idx < nums3.size()) {
                max_loss = max(max_loss, abs(nums1[i] - nums2[i]) - abs(nums3[low_idx] - nums2[i]));
            }
            if(low_idx >= 1) {
                max_loss = max(max_loss, abs(nums1[i] - nums2[i]) - abs(nums3[low_idx - 1] - nums2[i]));
            }
        }
        return (curr - max_loss + mod) % mod;
    }
};
