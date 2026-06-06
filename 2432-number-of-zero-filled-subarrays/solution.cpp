class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int l = 0, n = nums.size();
        while(l < n) {
            while(l < n && nums[l] != 0) l++;
            if(l >= n) break;
            int r = l;
            while(r < n && nums[r] == 0) r++;
            long long len = r - l;
            ans += (1LL + len) * len / 2LL;
            l = r;
        }
        return ans;
    }
};
