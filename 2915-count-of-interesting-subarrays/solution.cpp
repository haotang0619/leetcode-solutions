class Solution {
public:
    // Saw all hints
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        vector<int> cnt(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); i++) {
            cnt[i] = cnt[i - 1] + (nums[i - 1] % modulo == k ? 1 : 0);
        }
        unordered_map<int, int> ump;
        long long ans = 0;
        for(int i = 0; i < cnt.size(); i++) {
            int target = (cnt[i] + modulo - k) % modulo;
            if(ump.find(target) != ump.end()) ans += ump[target];
            int now = cnt[i] % modulo;
            if(ump.find(now) == ump.end()) ump[now] = 0;
            ump[now]++;
        }
        return ans;
    }
};
