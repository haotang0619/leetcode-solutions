class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](auto& a, auto& b) {
            return nums[a] < nums[b];
        });
        sort(nums.begin(), nums.end());
        
        vector<int> ans(n);
        for(int l = 0, r = 1; r <= n; r++) {
            if(r == n || abs(nums[r] - nums[r - 1]) > limit) {
                sort(indices.begin() + l, indices.begin() + r);
                for(int i = l; i < r; i++) ans[indices[i]] = nums[i];
                l = r;
            }
        }
        return ans;
    }
};
