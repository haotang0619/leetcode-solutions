class Solution {
public:
    int mod = 1e9 + 7;
    int nthMagicalNumber(int n, int a, int b) {
        int lcm = a * b / gcd(a, b);
        int cnt = lcm / a + lcm / b - 1;
        int quo = n / cnt, rem = n % cnt;
        long long ans = (long long)quo * lcm % mod;
        if(rem == 0) return ans;
        
        int x = a, y = b, now = min(x, y);
        while(--rem > 0) {
            if(x < y) x += a, now = min(x, y);
            else y += b, now = min(x, y);
        }
        ans = (ans + now) % mod;
        return ans;
    }
};
