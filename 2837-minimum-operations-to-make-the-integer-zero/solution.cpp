class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long n1 = num1, n2 = num2;
        for (int i = 1; i <= 61; i++) {
            n1 -= n2;
            if (n1 <= 0) return -1;
            int cnt = __builtin_popcountll(n1); // count of '1's in binary
            if (cnt <= i && n1 >= i) return i;
        }
        return -1;
    }
};
