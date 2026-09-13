class Solution {
public:
    int mod = 1e9 + 7;
    int fastPow(long long a, int b) {
        long long res = 1;
        while(b > 0) {
            if(b & 1) res = (res * a) % mod;
            a = (a * a) % mod, b >>= 1;
        }
        return res;
    }
    
    int stringCount(int n) {
        if(n < 4) return 0;
        
        long long all1 = fastPow(26, n);
        long long withoutOne1 = fastPow(25, n);
        long long withoutTwo1 = fastPow(24, n);
        long long withoutThree1 = fastPow(23, n);
        long long ans1 = (all1 - withoutOne1 * 3 + withoutTwo1 * 3 - withoutThree1) % mod;

        // Asked GPT for this part
        long long all2 = fastPow(25, n - 1);
        long long withoutOne2 = fastPow(24, n - 1);
        long long withoutTwo2 = fastPow(23, n - 1);
        long long ans2 = n * (all2 - withoutOne2 * 2 + withoutTwo2) % mod;

        long long ans = (ans1 - ans2) % mod;
        return ans < 0 ? (ans + mod) : ans;
    }
};
