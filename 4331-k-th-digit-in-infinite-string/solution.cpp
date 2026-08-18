class Solution {
public:
    int kthDigit(long long k) {
        if(k <= 9) return k;
        long long digits = 1, acc = 0, b = 10;
        while(acc < k) {
            acc += digits * (b - (b / 10));
            digits++, b *= 10;
        }
        digits--, b /= 10;
        acc -= digits * (b - (b / 10));
        long long left = k - acc;
        long long len = 10 * digits;
        long long bks = left / len, rem = left % len;
        long long init = 1;
        for(long long x = 1; x < digits; x++) init *= 10;
        init += bks * 10;
        if(rem == 0) {
            long long p = (init - 10) / 10;
            if(p % 2 == 0) return 9;
            return 0;
        }
        long long cnt = 0;
        while(rem >= digits) cnt++, rem -= digits;
        if(rem == 0) {
            long long p = init / 10;
            if(p % 2 == 0) return cnt - 1;
            else return 9 - (cnt - 1);
        }
        long long p = init / 10;
        if(p % 2 == 0) init += cnt;
        else init = init + 9 - cnt;
        string s = to_string(init);
        return s[rem - 1] - '0';
    }
};
