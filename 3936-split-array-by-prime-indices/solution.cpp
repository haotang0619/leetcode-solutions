class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i * i < n; i++) {
            if(!isPrime[i]) continue;
            for(int j = i + i; j < n; j += i) isPrime[j] = false;
        }
        long long sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++) {
            isPrime[i] ? (sum1 += (long long)nums[i]) : (sum2 += (long long)nums[i]);
        }
        return abs(sum1 - sum2);
    }
};
