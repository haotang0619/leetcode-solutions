class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long n1 = abs((long long)n);
        while(n1 > 0){
            if(n1 & 1) ans = ans * x;
            x = x * x;
            n1 >>= 1;
        }
        return n >= 0 ? ans : (1 / ans);
    }
};
