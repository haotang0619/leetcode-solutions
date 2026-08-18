class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long base = 1;
        int len = (long long)right - left + 1;
        int ans = 0;
        while(len > base) base *= 2;
        while(base < INT_MAX) {
            if((left & base) > 0 && (right & base) > 0) ans |= base;
            base *= 2;
        }
        return ans;
    }
};
