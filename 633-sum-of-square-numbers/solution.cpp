class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i = 0; i * i <= c; i++) {
            long long left = c - i * i;
            double res = sqrt(left);
            int r = floor(res);
            if((double)r == res) return true;
        }
        return false;
    }
};
