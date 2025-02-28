class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans = 0;
        long long div = abs((long long)divisor);
        long long absDividend = abs((long long)dividend);

        while(div < absDividend) div <<= 1;
        while(div >= abs((long long)divisor)) {
            ans <<= 1;
            if(absDividend - div >= 0) {
                ans |= 1;
                absDividend -= div;
            }
            div >>= 1;
        }
        ans = (long long)dividend * (long long)divisor > 0 ? ans : -ans;
        return ans > INT_MAX ? INT_MAX : (ans < INT_MIN ? INT_MIN : ans);
    }
};
