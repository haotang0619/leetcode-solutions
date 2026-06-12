class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> pSum(n + 1, 0);
        mp[0]++;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            pSum[i + 1] = pSum[i] + nums[i];
            int target = pSum[i + 1] - k;
            if(mp.contains(target)) ans += mp[target];
            mp[pSum[i + 1]]++;
        }
        return ans;
    }
};
