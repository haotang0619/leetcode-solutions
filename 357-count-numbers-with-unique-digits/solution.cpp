class Solution {
public:
    int comb(int n, int k) {
        k = min(k, n - k);
        if(k == 0) return 1;
        int res = 1;
        for(int i = 0; i < k; i++) res *= (n - i);
        for(int i = k; i >= 1; i--) res /= i;
        return res;
    }

    int fac(int n) {
        if(n == 0) return 1;
        int ans = n;
        while(--n > 0) ans *= n;
        return ans;
    }

    int countNumbersWithUniqueDigits(int n) {
        int ans = 1;
        for(int i = 1; i <= n; i++) {
            int cnt = 9 * comb(9, i - 1) * fac(i - 1);
            ans += cnt;
        }
        return ans;
    }
};
