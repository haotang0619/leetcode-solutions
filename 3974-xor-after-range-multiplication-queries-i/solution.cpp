class Solution {
public:
    long long mod = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for(int i = l; i <= r; i += k) {
                long long res = nums[i];
                res = (res * (long long)v) % mod;
                nums[i] = (int)res;
            }
        }
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++) ans ^= nums[i];
        return ans;
    }
};
