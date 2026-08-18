class Solution {
public:
    double findMed(vector<int>& nums1, vector<int>& nums2, int l, int r, int i1, int i2, int j1, int j2) {
        int len1 = i2 - i1 + 1, len2 = j2 - j1 + 1;
        if(len1 > len2) return findMed(nums2, nums1, l, r, j1, j2, i1, i2);
        if(i1 > i2) return (double)(nums2[j1 + l - 1] + nums2[j1 + r - 1]) / 2;

        if(i1 == i2) {
            int num1 = nums2[j1 + l - 1];
            int num2 = (j1 + r <= nums2.size()) ? nums2[j1 + r - 1] : INT_MAX;
            if(nums1[i1] >= num2) return (double)(num1 + num2) / 2;
            if(nums1[i1] >= num1) return (double)(num1 + nums1[i1]) / 2;
            if(l == r) {
                num1 = nums1[i1];
                if(j1 + l - 2 >= 0) num1 = max(num1, nums2[j1 + l - 2]);
                return num1;
            }
            num2 = num1, num1 = nums1[i1];
            if(j1 + l - 2 >= 0) num1 = max(num1, nums2[j1 + l - 2]);
            return (double)(num1 + num2) / 2;
        }

        int mid = j1 + (j2 - j1) / 2;
        int idx = upper_bound(nums1.begin() + i1, nums1.begin() + i2 + 1, nums2[mid]) - nums1.begin() - 1;
        int lSize = (mid - j1 + 1) + (idx - i1 + 1);
        if(lSize == l) {
            if(l == r) return nums2[mid];
            double num1 = nums2[mid], num2 = INT_MAX;
            if(mid + 1 < nums2.size()) num2 = min(num2, (double)nums2[mid + 1]);
            if(idx + 1 < nums1.size()) num2 = min(num2, (double)nums1[idx + 1]);
            return (num1 + num2) / 2;
        }
        if(lSize > l) return findMed(nums1, nums2, l, r, i1, idx, j1, mid);
        return findMed(nums1, nums2, l - lSize, r - lSize, idx + 1, i2, mid + 1, j2);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int l = (m + n + 1) / 2, r = (m + n + 2) / 2;
        return findMed(nums1, nums2, l, r, 0, m - 1, 0, n - 1);
    }
};
