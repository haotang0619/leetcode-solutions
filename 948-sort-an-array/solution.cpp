class Solution {
public:
    void mergeSort(vector<int>& nums, int l, int r) {
        if(l >= r) return;
        if(r - l <= 1) {
            if(nums[l] > nums[r]) swap(nums[l], nums[r]);
            return;
        }
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        vector<int> tmp(r - l + 1);
        int i1 = l, i2 = m + 1, i3 = 0;
        while(i1 <= m && i2 <= r) {
            if(nums[i1] <= nums[i2]) tmp[i3++] = nums[i1++];
            else tmp[i3++] = nums[i2++];
        }
        while(i1 <= m) tmp[i3++] = nums[i1++];
        while(i2 <= r) tmp[i3++] = nums[i2++];
        for(int i = 0; i <= r - l; i++) nums[l + i] = tmp[i];
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};
