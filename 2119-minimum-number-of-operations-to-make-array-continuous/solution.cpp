class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = n;
        unordered_map<int, int> mp;
        for(int i = 0, j = 0; i < n; i++) {
            int minNow = nums[i], maxNow = minNow + n - 1;
            while(j < n && nums[j] <= maxNow) {
                mp[nums[j]]++, j++;
            }
            ans = min(ans, n - (int)mp.size());
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
        }
        return ans;
    }
};
