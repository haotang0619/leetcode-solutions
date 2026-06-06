class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size(), ans = 0;
        while(i < n1 && j < n2) {
            j = max(j, i);
            while(j < n2 && nums2[j] >= nums1[i]) {
                ans = max(ans, j - i);
                j++;
            }
            i++;
        }
        return ans;
    }
};
