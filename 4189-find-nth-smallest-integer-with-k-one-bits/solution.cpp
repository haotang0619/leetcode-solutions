// Figured out by myself
class Solution {
public:
    long long perm(int n, int m) {
        if(n == 0 || n < m) return 0;
        int m1 = n - m;
        int j = 1, x = max(m, m1), y = min(m, m1);
        long long res = 1;
        for(int i = n; i > x; i--) {
            res *= i;
            while(j <= y && res % j == 0) res /= j++;
        }
        while(j <= y) res /= j++;
        return res;
    }

    long long nthSmallest(long long n, int k) {
        string s(51, '0');
        int cnt = 0;
        for(int i = 0; i <= 50 && cnt < k; i++) {
            long long res = perm(50 - i, k - cnt);
            if(res >= n) s[i] = '0';
            else s[i] = '1', n -= res, cnt++;
        }
        return stoll(s, nullptr, 2);
    }
};
