class Solution {
public:
    int mod = 1e9 + 7;

    void findAll1D(vector<vector<int>>& v, vector<int> &now, int &m) {
        if(now.size() == m) {
            v.push_back(now);
            return;
        }
        for(int i = 0; i <= 2; i++) {
            if(now.size() == 0 || now.back() != i) {
                now.push_back(i);
                findAll1D(v, now, m);
                now.pop_back();
            }
        }
    }

    bool check(vector<int> &a, vector<int> &b) {
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == b[i]) return false;
        }
        return true;
    }

    int colorTheGrid(int m, int n) {
        vector<vector<int>> v;
        vector<int> now;
        findAll1D(v, now, m);
        int size = v.size();
        vector<vector<int>> dp(n, vector<int>(size, 0));
        for(int i = 0; i < size; i++) dp[0][i] = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < size; j++) {
                int now = 0;
                for(int k = 0; k < size; k++) {
                    if(check(v[j], v[k])) now = (now + dp[i - 1][k]) % mod;
                }
                dp[i][j] = now;
            }
        }
        int ans = 0;
        for(int i = 0; i < size; i++) {
            ans = (ans + dp[n - 1][i]) % mod;
        }
        return ans;
    }
};
