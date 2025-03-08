class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        vector<int> nums;
        unordered_map<int, int> mp;
        for(auto x : nums1) for(auto y : nums2) nums.push_back(x + y);
        for(auto x : nums3) for(auto y : nums4) mp[x + y]++;
        int cnt = 0;
        for(auto x : nums) cnt += mp[-x];
        return cnt;
    }
};
