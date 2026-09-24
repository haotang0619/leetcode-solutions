class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0, base = 1, carry = 0;
        while(true) {
            int a1 = a & base, b1 = b & base;
            if(a1 != 0 && b1 != 0) {
                if(carry == 1) ans |= base;
                carry = 1;
            } else if((a1 | b1) != 0) {
                if(carry == 0) ans |= base;
            } else {
                if(carry == 1) ans |= base;
                carry = 0;
            }
            if(base == INT_MIN) break;
            base <<= 1;
        }
        return ans;
    }
};
