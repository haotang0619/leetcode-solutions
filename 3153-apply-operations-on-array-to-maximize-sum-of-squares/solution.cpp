class Solution {
public:
    int mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> digitCnts(32, 0);
        for(auto& num : nums) {
            for(int i = 0; i < 32; i++) {
                if((num & (1 << i)) != 0) digitCnts[i]++;
            }
        }
        long long ans = 0;
        while(k--) {
            long long now = 0;
            for(int i = 31; i >= 0; i--) {
                if(digitCnts[i] > 0) now |= (1 << i), digitCnts[i]--;
            }
            ans = (ans + (now * now)) % mod;
        }
        return ans;
    }
};
