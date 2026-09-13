class Solution {
public:
    bool checkDivisibility(int n) {
        int ds = 0, dp = 1, m = n;
        while(n > 0) ds += n % 10, dp *= n % 10, n /= 10;
        return m % (ds + dp) == 0;
    }
};
