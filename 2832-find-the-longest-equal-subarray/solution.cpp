class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<pair<int, int>>> mp;
        int n = nums.size();
        int prev = nums[0], l = 0;
        for(int r = 1; r < n; r++) {
            if(nums[r] != prev) mp[prev].push_back({l, r - 1}), l = r;
            prev = nums[r];
        }
        mp[prev].push_back({l, n - 1});
        int ans = 0;
        for(auto& [num, v] : mp) {
            int l = 0, len = 0, used = 0, sz = v.size();
            for(int r = 0; r < sz; r++) {
                len += v[r].second - v[r].first + 1;
                if(r > 0) {
                    int gap = v[r].first - v[r - 1].second - 1;
                    used += gap;
                }
                while(used > k) {
                    len -= v[l].second - v[l].first + 1;
                    int gap = v[l + 1].first - v[l].second - 1;
                    used -= gap;
                    l++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
