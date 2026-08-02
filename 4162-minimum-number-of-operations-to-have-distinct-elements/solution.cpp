class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> mp;
        int need = 0;
        for(auto num : nums) ++mp[num];
        for(auto& [x, cnt] : mp) {
            if(cnt >= 2) need++;
        }
        if(need == 0) return 0;
        for(int i = 0; i < n; i += 3) {
            ++ans;
            if(mp[nums[i]] >= 2 && --mp[nums[i]] <= 1) need--;
            if(i + 1 < n && mp[nums[i + 1]] >= 2 && --mp[nums[i + 1]] <= 1) need--;
            if(i + 2 < n &&mp[nums[i + 2]] >= 2 && --mp[nums[i + 2]] <= 1) need--;
            if(need <= 0) break;
        }
        return ans;
    }
};
