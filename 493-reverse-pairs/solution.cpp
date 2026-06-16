class Solution {
public:
    int findAns(vector<int>& nums, int l, int r) {
        if(l >= r) return 0;
        int now = 0;
        int m = l + (r - l) / 2;
        now += findAns(nums, l, m) + findAns(nums, m + 1, r);
        for(int i = l, j = m + 1; i <= m; i++) {
            while(j <= r && (long long)nums[i] > 2LL * nums[j]) j++;
            now += j - (m + 1);
        }
        vector<int> tmp(r - l + 1);
        int i1 = l, j1 = m + 1, k = 0;
        while(i1 <= m && j1 <= r) {
            if(nums[i1] <= nums[j1]) tmp[k++] = nums[i1++];
            else tmp[k++] = nums[j1++];
        }
        while(i1 <= m) tmp[k++] = nums[i1++];
        while(j1 <= r) tmp[k++] = nums[j1++];
        for(int i = l; i <= r; i++) nums[i] = tmp[i - l];
        return now;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return findAns(nums, 0, n - 1);
    }
};
