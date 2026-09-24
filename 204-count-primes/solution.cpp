// Learned Euler's Sieve from this
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0;
        bool isPrime[n];
        fill_n(isPrime, n, true);
        int primes[n], sz = 0;
        for(long long i = 2; i < n; i++) {
            if(isPrime[i]) primes[sz++] = i;
            for(int j = 0; j < sz; j++) {
                int p = primes[j];
                if(i * p >= n) break;
                isPrime[i * p] = false;
                if(i % p == 0) break;
            }
        }
        return sz;
    }
};
