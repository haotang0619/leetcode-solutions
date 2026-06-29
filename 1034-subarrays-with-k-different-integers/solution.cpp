// Saw topics
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0, cnt = 0, l1 = 0, l2 = 0, r = 0, n = nums.size();
        while(r < n) {
            if(mp[nums[r]] == 0) cnt++;
            mp[nums[r]]++;
            if(cnt > k) {
                while(cnt > k) {
                    if(--mp[nums[l2++]] == 0) cnt--;
                }
                l1 = l2;
            }
            while(cnt == k && mp[nums[l2]] > 1) mp[nums[l2++]]--;
            if(cnt == k) ans += l2 - l1 + 1;
            r++;
        }
        return ans;
    }
};
