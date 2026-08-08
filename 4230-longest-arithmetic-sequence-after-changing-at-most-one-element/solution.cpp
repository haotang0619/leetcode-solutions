class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int ans = 3, n = nums.size();
        vector<tuple<int, int, int>> v; // [l, r, gap]
        for(int l = 0; l + 1 < n; l++) {
            int r = l + 1;
            int gap = nums[r] - nums[l];
            while(r < n && (nums[r] - nums[r - 1]) == gap) r++;
            v.push_back({l, r - 1, gap});
            l = r - 2;
        }
        for(int i = 0; i < v.size(); i++) {
            auto& [l, r, gap] = v[i];
            int len = r - l + 1;
            ans = max(ans, len);
            if(l > 0 || r < n - 1) ans = max(ans, len + 1);
            if(l > 1) {
                int prev1 = nums[l] - gap, prev2 = prev1 - gap;
                if(nums[l - 1] == prev1 || nums[l - 2] == prev2) {
                    ans = max(ans, len + 2);
                }
            }
            if(r < n - 2) {
                int next1 = nums[r] + gap, next2 = next1 + gap;
                if(nums[r + 1] == next1 || nums[r + 2] == next2) {
                    ans = max(ans, len + 2);
                }
            }
        }
        for(int i = 0; i + 3 < v.size(); i++) {
            auto& [l1, r1, g1] = v[i];
            auto& [l2, r2, g2] = v[i + 3];
            if(r1 + 1 < l2 - 1) continue;
            if(g1 == g2 && nums[r1] + g1 * 2 == nums[l2]) {
                ans = max(ans, r2 - l1 + 1);
            }
        }
        return ans;
    }
};
