class Solution {
public:
    int mod = 1e9 + 7;

    // Saw solutions
    int numberOfGoodPartitions(vector<int>& nums) {
        // 1. Find last positions
        map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) mp[nums[i]] = i;
        
        // 2. Do math
        int ans = 1;
        for(int i = 0, j = 0; i < n; i++) {
            // KEY: Double it here because it surpasses one of the last position, where we can choose whether to start a new subarray.
            if(i > j) ans = (ans * 2) % mod;
            j = max(j, mp[nums[i]]);
        }
        return ans;
    }
};
