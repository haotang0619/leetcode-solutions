class Solution {
public:
    int getSum(int a, int b) {
        long long pos = 1;
        int ans = 0, carry = 0;
        while(pos <= pow(2, 33)) {
            int x = a & 1, y = b & 1;
            if(x == 0 && y == 0) {
                if(carry == 1) ans |= pos;
                carry = 0;
            } else if(x ^ y == 1) {
                if(carry != 1) ans |= pos;
            } else {
                if(carry == 1) ans |= pos;
                else carry = 1;
            }
            pos <<= 1;
            a >>= 1;
            b >>= 1;
        }
        return ans;
    }
};
