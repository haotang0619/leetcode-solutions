class Solution {
public:
    vector<int> findPrimeFacs(vector<bool>& isPrime, int x) {
        vector<int> facs;
        for(long long i = 1; i * i <= x; i++) {
            if(x % i != 0) continue;
            if(isPrime[i]) facs.push_back(i);
            int j = x / i;
            if(i == j) continue;
            if(isPrime[j]) facs.push_back(j);
        }
        return facs;
    }
    
    int findValidSplit(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime(mx + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(long long i = 2; i <= mx; i++) {
            if(!isPrime[i]) continue;
            for(long long j = i * i; j <= mx; j += i) isPrime[j] = false;
        }
        int n = nums.size();
        vector<vector<int>> primeFacs(n);
        vector<int> facCnts(1e6 + 1, 0);
        for(int i = 0; i < n; i++) {
            primeFacs[i] = findPrimeFacs(isPrime, nums[i]);
            if(i > 0) {
                for(auto& p : primeFacs[i]) facCnts[p]++;
            }
        }
        unordered_set<int> shared;
        for(int i = 0; i < n - 1; i++) {
            for(auto& p : primeFacs[i]) {
                if(facCnts[p] > 0) shared.insert(p);
            }
            if(shared.size() == 0) return i;
            for(auto& p : primeFacs[i + 1]) {
                if(--facCnts[p] == 0) shared.erase(p);
            }
        }
        return -1;
    }
};
