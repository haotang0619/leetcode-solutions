class Solution {
public:
    int mod = 1e9 + 7;
    int fastPow(long long a, int b) {
        long long res = 1;
        while(b > 0) {
            if(b & 1) res = (res * a) % mod;
            a = (a * a) % mod, b >>= 1;
        }
        return res;
    }

    int count(vector<long long>& facs, int n, int a, int b) {
        int invA = fastPow(facs[a], mod - 2), invB = fastPow(facs[b], mod - 2);
        long long res = facs[n];
        return ((res * invA) % mod * invB) % mod;
    }
    
    int countVisiblePeople(int n, int pos, int k) {
        long long ans = 0;
        int nLeft = pos, nRight = n - 1 - pos;
        vector<long long> facs(n + 1, 1);
        for(int i = 2; i <= n; i++) facs[i] = (facs[i - 1] * i) % mod;
        
        for(int l = 0; l <= k; l++) {
            int r = k - l;
            if(l > nLeft || r > nRight) continue;
            long long addLeft = count(facs, nLeft, l, nLeft - l);
            long long addRight = count(facs, nRight, r, nRight - r);
            long long add = (addLeft * addRight) % mod;
            ans = (ans + add) % mod;
        }
        ans = (ans * 2) % mod;
        return (ans < 0) ? (ans + mod) : ans;
    }
};
