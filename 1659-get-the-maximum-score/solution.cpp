class Solution {
public:
    int mod = 1e9 + 7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<long long> dp1(n1, 0), dp2(n2, 0);
        int i1 = 0, i2 = 0;
        while(i1 < n1 && i2 < n2) {
            dp1[i1] = max(dp1[i1], nums1[i1] + (i1 >= 1 ? dp1[i1 - 1] : 0));
            dp2[i2] = max(dp2[i2], nums2[i2] + (i2 >= 1 ? dp2[i2 - 1] : 0));
            if(nums1[i1] == nums2[i2]) {
                dp1[i1] = dp2[i2] = max(dp1[i1], dp2[i2]);
                i1++, i2++;
            } else if(nums1[i1] < nums2[i2]) i1++;
            else i2++;
        }
        while(i1 < n1) dp1[i1++] = max(dp1[i1], nums1[i1] + (i1 >= 1 ? dp1[i1 - 1] : 0));
        while(i2 < n2) dp2[i2++] = max(dp2[i2], nums2[i2] + (i2 >= 1 ? dp2[i2 - 1] : 0));
        return max(dp1[n1 - 1], dp2[n2 - 1]) % mod;
    }
};
