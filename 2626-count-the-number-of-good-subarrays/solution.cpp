class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = 0;
        long long ans = 0, cnt = 0;
        mp[nums[l]] = 1;
        for(int r = 1; r < nums.size(); r++) {
            if(mp.find(nums[r]) == mp.end()) mp[nums[r]] = 0;
            mp[nums[r]]++;
            int c1 = mp[nums[r]];
            if(c1 >= 2) cnt += (c1 - 1);
            while(cnt >= k) {
                ans += nums.size() - r;
                mp[nums[l]]--;
                int c2 = mp[nums[l++]];
                cnt -= c2;
            }
        }
        return ans;
    }
};
