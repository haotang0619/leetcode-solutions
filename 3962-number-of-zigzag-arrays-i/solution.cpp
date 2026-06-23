class Solution {
public:
    int mod = 1e9 + 7;

    void reBuildPSum(vector<int>& init1, vector<int>& init2, vector<int>& pSum1, vector<int>& pSum2) {
        for(int i = 1; i <= init1.size(); i++) {
            pSum1[i] = (pSum1[i - 1] + init1[i - 1]) % mod;
            pSum2[i] = (pSum2[i - 1] + init2[i - 1]) % mod;
        }
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l;
        vector<int> init1(m + 1, 1), init2(m + 1, 1);
        vector<int> pSum1(m + 2, 0), pSum2(m + 2, 0); // pSum1: peak, pSum2: valley
        reBuildPSum(init1, init2, pSum1, pSum2);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= m; j++) {
                init1[j] = (pSum2[j] - pSum2[0]) % mod;
                init2[j] = (pSum1[m + 1] - pSum1[j + 1]) % mod;
            }
            reBuildPSum(init1, init2, pSum1, pSum2);
        }
        int ans = (pSum1[m + 1] + pSum2[m + 1]) % mod;
        return (ans < 0 ? ans + mod : ans) % mod;
    }
};
