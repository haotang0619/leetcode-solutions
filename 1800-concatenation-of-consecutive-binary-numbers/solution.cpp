class Solution {
public:
    int mod = 1e9 + 7;
    int concatenatedBinary(int n) {
        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            int shift = floor(log2(i)) + 1;
            ans <<= shift;
            ans += i;
            ans %= mod;
        }
        return ans;
    }
};
