class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto x : nums) mp[x]++;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        int ans = INT_MIN;
        for(auto x : nums) {
            int y = sum - x;
            if(y % 2 == 0 && mp[y / 2] >= (x == y / 2 ? 2 : 1)) {
                ans = max(ans, x);
            }
        }
        return ans;
    }
};
