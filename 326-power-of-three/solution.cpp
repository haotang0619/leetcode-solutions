class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 ? pow(3, floor(log10(n) / log10(3))) == n : false;
    }
};
