class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> nums1, nums2, nums3;
        for(auto x : nums) {
            if(x < pivot) nums1.push_back(x);
            else if(x == pivot) nums2.push_back(x);
            else nums3.push_back(x);
        }
        int cnt = 0;
        for(int i = 0; i < nums1.size(); i++) nums[cnt++] = nums1[i];
        for(int i = 0; i < nums2.size(); i++) nums[cnt++] = nums2[i];
        for(int i = 0; i < nums3.size(); i++) nums[cnt++] = nums3[i];
        return nums;
    }
};
