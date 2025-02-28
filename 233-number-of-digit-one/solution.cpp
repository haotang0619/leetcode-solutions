class Solution {
public:
    int countDigitOne(int n) {
        int num = n;
        long long ans = 0;
        long long divider = 1;
        while(num > 0) {
            divider *= 10;
            long long m = divider / 10;
            long long r = n % divider;
            long long curr = (n / divider) * m;
            curr += (r >= m ? min((r - m + 1), m) : 0);
            // cout << curr << endl;
            ans += curr;
            num /= 10;
        }
        return (int)ans;
    }
};
