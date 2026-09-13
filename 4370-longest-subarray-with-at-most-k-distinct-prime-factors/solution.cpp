class Solution {
public:
    vector<int> findPrimeFacs(vector<bool>& isPrime, long long now) {
        vector<int> v;
        for(long long i = 1; i * i <= now; i++) {
            if(now % i != 0) continue;
            if(isPrime[i]) v.push_back(i);
            int j = now / i;
            if(i == j) continue;
            if(isPrime[j]) v.push_back(j);
        }
        return v;
    }
    
    int longestSubarray(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime(mx + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(long long i = 2; i <= mx; i++) {
            if(!isPrime[i]) continue;
            for(long long j = i * i; j <= mx; j += i) isPrime[j] = false;
        }
        vector<int> mp(mx + 1, 0);
        vector<vector<int>> primeFacs(mx + 1);
        int ans = 0, cnt = 0, n = nums.size();
        for(int l = 0, r = 0; r < n; r++) {
            long long now = nums[r];
            if(primeFacs[now].size() == 0) {
                primeFacs[now] = findPrimeFacs(isPrime, now);
            }
            for(auto& p : primeFacs[now]) {
                if(++mp[p] == 1) cnt++;
            }
            while(cnt > k) {
                long long prev = nums[l];
                if(primeFacs[prev].size() == 0) {
                    primeFacs[prev] = findPrimeFacs(isPrime, prev);
                }
                for(auto& p : primeFacs[prev]) {
                    if(--mp[p] == 0) cnt--;
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
