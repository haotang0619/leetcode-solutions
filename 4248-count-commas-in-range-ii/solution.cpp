class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;
        long long ans = 0, cnt = 1, now = 1000;
        while(now <= n) {
            ans += (min(now * 1000 - 1, n) - now + 1) * cnt;
            now *= 1000, cnt++;
        }
        return ans;
    }
};
