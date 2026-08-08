class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<bool> isPrime(2e5 + 1, true);
        vector<int> primes, nonPrimes = {1};
        for(long long i = 2; i <= 2e5; i++) {
            if(!isPrime[i]) {
                nonPrimes.push_back(i);
                continue;
            }
            primes.push_back(i);
            for(long long j = i * i; j <= 2e5; j += i) isPrime[j] = false;
        }
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            auto& v = (i % 2 == 0) ? primes : nonPrimes;
            int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            ans += v[idx] - nums[i];
        }
        return ans;
    }
};
