class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 ? pow(4, floor(log10(n) / log10(4))) == n : false;
    }
};
