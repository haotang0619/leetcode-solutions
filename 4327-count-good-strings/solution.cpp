class Solution {
public:
    int mod = 1e9 + 7;
    using Mat = array<array<long long, 2>, 2>;
    
    Mat matMul(const Mat& A, const Mat& B) {
        Mat C{};
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
        return C;
    }

    Mat fastPow(Mat a, long long b) {
        Mat res = {{{1, 0}, {0, 1}}}; // Identity matrix
        while(b) {
            if(b & 1) res = matMul(res, a);
            a = matMul(a, a), b >>= 1;
        }
        return res;
    }

    int countGoodStrings(long long n) {
        // The answer is simply 2 * F(n), where F is the Fibonacci sequence.
        Mat base = {{{1, 1}, {1, 0}}};
        auto res = fastPow(base, n - 1);
        return (2 * res[0][0]) % mod;
    }
};
