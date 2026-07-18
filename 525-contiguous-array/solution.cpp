class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = 0, cnt0 = 0, cnt1 = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            (nums[i] == 0 ? cnt0 : cnt1)++;
            int diff = cnt0 - cnt1;
            if(mp.contains(diff)) ans = max(ans, i - mp[diff]);
            else mp[diff] = i;
        }
        return ans;
    }
};
