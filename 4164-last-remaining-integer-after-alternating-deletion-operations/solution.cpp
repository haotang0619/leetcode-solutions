class Solution {
public:
    long long lastInteger(long long n) {
        long long l = 1, r = n, now = n, gap = 1;
        int idx = 0;
        while(now > 1) {
            now = (now + 1) / 2, gap *= 2;
            if(idx == 0) r = l + gap * (now - 1);
            else l = r - gap * (now - 1);
            idx = 1 - idx;
        }
        return l;
    }
};
