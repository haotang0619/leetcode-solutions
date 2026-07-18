// Asked GPT, modified from my own code
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> mp(maxNum + 1, 0);
        for(auto& num : nums) mp[num]++;
        
        // Möbius function
        vector<int> mu(maxNum + 1);
        vector<int> primes;
        vector<bool> isPrime(maxNum + 1, true);
        mu[1] = 1;
        for(int i = 2; i <= maxNum; i++) {
            if(isPrime[i]) primes.push_back(i), mu[i] = -1;
            for(int& p : primes) {
                if(i * p > maxNum) break;
                isPrime[i * p] = false;
                if(i % p == 0) {
                    mu[i * p] = 0;
                    break;
                } else mu[i * p] = -mu[i];
            }
        }

        vector<int> mulCnt(maxNum + 1, 0);
        mulCnt[1] = nums.size();
        for(int i = 2; i <= maxNum; i++) {
            for(int j = i; j <= maxNum; j += i) mulCnt[i] += mp[j];
        }
        
        vector<long long> gcdCnt(maxNum + 1, 0);
        for(int i = 1; i <= maxNum; i++) {
            for(int j = 1; i * j <= maxNum; j++) {
                if(mu[j] == 0) continue;
                long long c = mulCnt[i * j];
                gcdCnt[i] += 1LL * mu[j] * c * (c - 1) / 2;
            }
        }
        
        vector<long long> pSum(maxNum + 2, 0);
        for(int i = 1; i < maxNum + 2; i++) pSum[i] = pSum[i - 1] + gcdCnt[i - 1];
        
        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            long long q = queries[i];
            int idx = upper_bound(pSum.begin(), pSum.end(), q) - pSum.begin();
            ans[i] = idx - 1;
        }
        return ans;
    }
};
