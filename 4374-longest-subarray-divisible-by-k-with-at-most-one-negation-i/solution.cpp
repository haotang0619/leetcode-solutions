class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            int sum = 0;
            vector<bool> v(k, 0);
            for(int j = i; j < n; j++) {
                sum += nums[j];
                int rem = (-2 * nums[j]) % k;
                if(rem < 0) rem += k;
                v[rem] = true;
                if(sum % k == 0) ans = max(ans, j - i + 1);
                else {
                    int rem = sum % k;
                    if(rem < 0) rem += k;
                    int need = k - rem;
                    if(v[need]) ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
