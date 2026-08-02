class Solution {
public:
    int largestPrime(int n) {
        vector<bool> isPrime(n + 1, true);
        vector<int> primes;
        for(int i = 2; i <= n; i++) {
            if(!isPrime[i]) continue;
            primes.push_back(i);
            for(long long j = (long long)i * i; j <= n; j += i) isPrime[j] = false;
        }
        long long now = 0;
        int ans = 0;
        for(auto it = primes.begin(); it != primes.end(); ++it) {
            now += *it;
            if(now > n) break;
            if(isPrime[now]) ans = now;
        }
        return ans;
    }
};
