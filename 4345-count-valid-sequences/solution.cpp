class Solution {
public:
    int mod = 1e9 + 7;

    int fastPow(long long a, int b) {
        long long res = 1;
        while(b > 0) {
            if(b % 2) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return (int)res;
    }
    
    long long comb (int n, int m) {
        long long ans = 1;
        m = min(m, n - m);
        for(long long i = n; i > n - m; i--) ans = (ans * i) % mod;
        for(long long j = 1; j <= m; j++) {
            long long inv = fastPow(j, mod - 2);
            ans = (ans * inv) % mod;
        }
        return ans;
    }
    
    int countValidSequences(int n, int k) {
        long long all = comb(n - 1, k - 1) % mod;
        if((n - k) % 2 == 1) return all;
        int left = (n - k) / 2;
        long long allOdds = comb(left + k - 1, k - 1) % mod;
        long long ans = (all - allOdds) % mod;
        return ans < 0 ? (ans + mod) : ans;
    }
};
