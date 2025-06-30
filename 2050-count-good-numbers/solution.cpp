class Solution {
public:
    int mod = 1e9 + 7;
    long long mod_pow(long long a, long long b){
        long long result = 1;
        a = a % mod;
        while (b > 0) {
            if (b % 2 == 1) result = (result * a) % mod;
            a = (a * a) % mod;
            b /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long odd_cnt = n / 2, even_cnt = n - n / 2;
        long long cnt1 = mod_pow(4, odd_cnt);
        long long cnt2 = mod_pow(5, even_cnt);
        return (int)((cnt1 * cnt2) % mod);
    }
};
