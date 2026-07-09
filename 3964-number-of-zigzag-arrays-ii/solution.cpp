// Saw all hints
// Asked GPT for Matrix Exponentiation
class Solution {
public:
    int mod = 1e9 + 7;
    using Matrix = vector<vector<long long>>;

    Matrix mul(Matrix& A, Matrix& B) {
        int M = A.size(), N = B.size(), K = B[0].size();
        Matrix C(M, vector<long long>(K, 0));
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                for (int k = 0; k < K; k++) {
                    C[i][k] = (C[i][k] + A[i][j] * B[j][k]) % mod;
                }
            }
        }
        return C;
    }

    Matrix identity(int n) {
        Matrix I(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) I[i][i] = 1;
        return I;
    }

    Matrix fastPow(Matrix base, int exp) {
        int n = base.size();
        Matrix res = identity(n);
        while (exp > 0) {
            if (exp & 1) res = mul(res, base);
            base = mul(base, base);
            exp >>= 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        // Transitions:
        // dp[n][k][0] = dp[n - 1][k + 1][1] + ... + dp[n - 1][m - 1][1]
        // dp[n][k][1] = dp[n - 1][k - 1][0] + ... + dp[n - 1][0][0]
        int m = r - l + 1;
        Matrix base(1, vector<long long>(2 * m, 1));
        base[0][m - 1] = base[0][m] = 0;
        Matrix transMat(2 * m, vector<long long>(2 * m, 0));
        for(int i = 0; i < 2 * m; i++) {
            for(int j = 0; j < 2 * m; j++) {
                if(i < m && j > m + i) transMat[i][j] = 1;
                if(i >= m && j < i - m) transMat[i][j] = 1;
            }
        }
        Matrix finalMat = fastPow(transMat, n - 1);
        Matrix res = mul(base, finalMat);
        int ans = 0;
        for(auto& x : res[0]) ans = (ans + x) % mod;
        return ans;
    }
};
