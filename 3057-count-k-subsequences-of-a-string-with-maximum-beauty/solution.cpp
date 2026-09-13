class Solution {
public:
    int mod = 1e9 + 7;
    int fastPow(long long a, int b) {
        long long res = 1;
        while(b > 0) {
            if(b & 1) res = res * a % mod;
            a = a * a % mod, b >>= 1;
        }
        return res;
    }

    int comb(int n, int k) {
        long long res = 1;
        k = min(k, n - k);
        for(int i = n; i > n - k; i--) res = res * i % mod;
        for(int i = k; i >= 1; i--) res = res * fastPow(i, mod - 2) % mod;
        return res;
    }
    
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        unordered_map<char, int> mp;
        for(auto& c : s) mp[c]++;
        if(mp.size() < k) return 0;
        
        vector<int> v;
        for(auto& [_, cnt] : mp) v.push_back(cnt);
        sort(v.rbegin(), v.rend());
        
        int until = v[k - 1];
        long long ans = 1, done = 0, last = 0;
        for(auto& cnt : v) {
            if(cnt < until) break;
            if(cnt == until) last++;
            else ans = ans * cnt % mod, done++;
        }
        long long res = (long long)comb(last, k - done) * fastPow(until, k - done) % mod;
        return (ans * res) % mod;
    }
};
