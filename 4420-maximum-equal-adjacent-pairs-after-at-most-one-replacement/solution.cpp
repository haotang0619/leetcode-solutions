class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> mp1;
        map<pair<int, int>, int> mp2;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                mp1[nums[i]]++, ans = max(ans, mp1[nums[i]]);
            } else {
                int mn = min(nums[i], nums[i + 1]), mx = max(nums[i], nums[i + 1]);
                mp2[{mn, mx}]++;
            }
        }
        int sum = 0;
        for(auto& [x, cnt] : mp1) sum += cnt;
        for(auto& [x, cnt] : mp2) ans = max(ans, sum + cnt);
        return ans;
    }
};
