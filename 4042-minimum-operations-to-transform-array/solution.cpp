class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int target = nums2[n], copied = -1e5;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int n1 = nums1[i], n2 = nums2[i];
            if(n1 > n2) swap(n1, n2);
            int diff = n2 - n1;
            ans += diff;
            int curr;
            if(n2 <= target) curr = n2;
            else if(n1 <= target) curr = target;
            else curr = n1;
            if(abs(target - copied) > abs(target - curr)) copied = curr;
        }
        ans += abs(target - copied) + 1;
        return ans;
    }
};
