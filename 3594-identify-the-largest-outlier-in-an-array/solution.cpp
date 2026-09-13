class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto& num : nums) mp[num]++;
        int ans = INT_MIN, sum = accumulate(nums.begin(), nums.end(), 0);
        for(auto& num : nums) {
            int left = sum - num;
            if(left % 2 != 0) continue;
            int target = left / 2;
            if(num == target && mp[target] >= 2 || num != target && mp[target] >= 1) {
                ans = max(ans, num);
            }
        }
        return ans;
    }
};
