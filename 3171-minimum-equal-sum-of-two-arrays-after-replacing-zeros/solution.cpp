class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        int zero_cnt1 = 0, zero_cnt2 = 0;
        for(auto x : nums1) zero_cnt1 += x == 0 ? 1 : 0;
        for(auto x : nums2) zero_cnt2 += x == 0 ? 1 : 0;
        long long target = max(sum1 + zero_cnt1, sum2 + zero_cnt2);
        return (target - sum1) >= zero_cnt1 && (target - sum2) >= zero_cnt2 && (zero_cnt1 > 0 || target == sum1) && (zero_cnt2 > 0 || target == sum2) ? target : -1;
    }
};
