class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        bool isPrime[right + 1];
        fill_n(isPrime, right + 1, true);
        vector<int> primes;
        for(long long i = 2; i <= right; i++) {
            if(isPrime[i]) primes.push_back(i);
            for(auto& p : primes) {
                if(i * p > right) break;
                isPrime[i * p] = false;
                if(i % p == 0) break;
            }
        }

        vector<int> v = {-1, -1};
        int prev = -1;
        for(auto& p : primes) {
            if(prev >= left && (v[0] == -1 || v[1] - v[0] > p - prev)) v = {prev, p};
            if(v[1] - v[0] == 2) break;
            prev = p;
        }
        return v;
    }
};
