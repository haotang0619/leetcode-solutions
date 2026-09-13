class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        unordered_map<int, int> mp1, mp2;
        for(auto& num : nums) mp2[num]++;
        for(int i = 0; i < n; i++) {
            mp1[nums[i]]++;
            mp2[nums[i]]--;
            if(mp2[nums[i]] == 0) mp2.erase(nums[i]);
            ans[i] = mp1.size() - mp2.size();
        }
        return ans;
    }
};
