class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1) return false;
        long long nll = abs((long long)n);
        while(nll > 1) {
            if(nll % 4 != 0) return false;
            nll /= 4;
        }
        return true;
    }
};
