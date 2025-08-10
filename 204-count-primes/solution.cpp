class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(max(n, 2), true);
        isPrime[0] = isPrime[1] = false;
        int ans = max(n - 2, 0);
        for(int i = 2; i < n; i++) {
            if(!isPrime[i]) continue;
            for(int j = i + i; j < n; j += i) {
                if(isPrime[j]) ans--;
                isPrime[j] = false;
            }
        }
        return ans;
    }
};
