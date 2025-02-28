class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]].push_back(i);
        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            for(auto x : mp[diff]) {
                if(i != x) return {i, x};
            }
        }
        return {};
    }
};
