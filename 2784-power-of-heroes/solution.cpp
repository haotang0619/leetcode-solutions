class Solution {
public:
    int mod = 1e9 + 7;
    int fastPow(long long a, int b) {
        long long res = 1;
        while(b > 0) {
            if(b & 1) res = res * a % mod;
            a = a * a % mod, b >>= 1;
        }
        return res;
    }
    
    int sumOfPower(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        long long ans = 0, base = 1, sSum = 0;
        for(int i = 1; i < n; i++) {
            sSum = (sSum + nums[i] * base) % mod;
            base = base * 2 % mod;
        }
        for(int i = 0; i < n; i++) {
            long long sq = (long long)nums[i] * nums[i] % mod;
            ans = (ans + sq * (nums[i] + sSum)) % mod;
            if(i + 1 < n) sSum = (sSum - nums[i + 1]) * fastPow(2, mod - 2) % mod;
        }
        return ans < 0 ? (ans + mod) : ans;
    }
};
