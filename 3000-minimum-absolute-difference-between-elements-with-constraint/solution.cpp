class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        map<int, int> mp;
        int ans = INT_MAX, n = nums.size();
        for(int j = x; j < n; j++) mp[nums[j] - nums[0]]++;
        for(int i = 0; i < n - x; i++) {
            int diff = nums[i] - nums[0];
            auto it = mp.lower_bound(diff);
            if(it != mp.end()) ans = min(ans, abs((*it).first - diff));
            if(it != mp.begin()) ans = min(ans, abs((*prev(it)).first - diff));
            if(ans == 0) break;
            mp[nums[i + x] - nums[0]]--;
            if(mp[nums[i + x] - nums[0]] == 0) mp.erase(nums[i + x] - nums[0]);
        }
        return ans;
    }
};
