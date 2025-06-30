class Solution {
public:
    long long minEnd(int n, int x) {
        int t = n - 1;
        long long ans = 0, p = 1;
        while(t > 0 || x > 0) {
            if(x & 1) ans += p;
            else ans += p * (t & 1), t >>= 1;
            x >>= 1, p <<= 1;
        }
        return ans;
    }
};
