class Solution {
public:
    int mod = 1e9 + 7;
    
    int fastPow(long long a, int b) {
        long long res = 1;
        while(b > 0) {
            if(b & 1) res = res * a % mod;
            a = a * a % mod, b >>= 1;
        }
        return (int)res;
    }

    int expSum(int k) {
        // (x^k - 1) / (x - 1), x = 10
        long long mulInv = fastPow(9, mod - 2);
        return (mulInv * (fastPow(10, k) - 1)) % mod;
    }
    
    int sumOfNumbers(int l, int r, int k) {
        long long opt = (r - l) + 1;
        long long poss = fastPow(opt, k - 1);
        long long cnt = (opt * poss) % mod;
        long long ans = 0;
        for(int i = l; i <= r; i++) ans = (ans + cnt * i * expSum(k)) % mod;
        int mulInv = fastPow(opt, mod - 2);
        ans = (ans * mulInv) % mod;
        return ans < 0 ? (ans + mod) : ans;
    }
};
