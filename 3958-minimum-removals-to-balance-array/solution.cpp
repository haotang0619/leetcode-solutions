class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), ans = INT_MAX;
        sort(nums.begin(), nums.end());
        while(l < n) {
            while(r < n && (long long)nums[l] * k >= (long long)nums[r]) {
                ans = min(ans, l + n - r - 1);
                r++;
            }
            if(r == n) break;
            l++;
        }
        return ans;
    }
};
