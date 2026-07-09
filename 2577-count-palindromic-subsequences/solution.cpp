class Solution {
public:
    int mod = 1e9 + 7;
    int countPalindromes(string s) {
        int n = s.size();
        vector<int> cnts1(10, 0);
        vector<vector<long long>> cnts2(n, vector<long long>(100, 0));
        for(int i = n - 1; i >= 3; i--) {
            int d = s[i] - '0';
            if(i < n - 1) {
                for(int a = 0; a < 100; a++) cnts2[i][a] = cnts2[i + 1][a];
            }
            for(int x = 0; x < 10; x++) cnts2[i][d * 10 + x] += cnts1[x];
            cnts1[d]++;
        }

        long long ans = 0;
        cnts1.assign(10, 0);
        vector<long long> cnts3(100, 0);
        for(int i = 0; i + 2 < n; i++) {
            int d = s[i] - '0';
            if(i >= 2) {
                for(int a = 0; a < 100; a++) {
                    int b = (a % 10) * 10 + a / 10;
                    ans = (ans + cnts3[a] * cnts2[i + 1][b]) % mod;
                }
            }
            for(int x = 0; x < 10; x++) cnts3[x * 10 + d] += cnts1[x];
            cnts1[d]++;
        }
        return ans;
    }
};
