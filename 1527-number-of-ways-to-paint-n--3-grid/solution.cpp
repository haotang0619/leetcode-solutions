class Solution {
public:
    int mod = 1e9 + 7;

    void buildBase(vector<vector<int>>& base, vector<int>& now, int idx) {
        if(idx == 3) {
            base.push_back(now);
            return;
        }
        for(int i = 0; i < 3; i++) {
            if(idx > 0 && now[idx - 1] == i) continue;
            now.push_back(i);
            buildBase(base, now, idx + 1);
            now.pop_back();
        }
    }

    void buildParents(vector<vector<int>>& parents, vector<vector<int>>& base) {
        int m = base.size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                bool valid = true;
                for(int k = 0; k < 3; k++) {
                    if(base[i][k] == base[j][k]) {
                        valid = false;
                        break;
                    }
                }
                if(valid) parents[i].push_back(j);
            }
        }
    }

    int numOfWays(int n) {
        vector<vector<int>> base;
        vector<int> tmp;
        buildBase(base, tmp, 0);
        int m = base.size();
        vector<vector<int>> parents(m);
        buildParents(parents, base);
        vector<vector<int>> dp(2, vector<int>(m, 1));
        int prev = 0, now = 1;
        while(--n) {
            for(int i = 0; i < m; i++) {
                dp[now][i] = 0;
                for(auto &p : parents[i]) dp[now][i] = (dp[now][i] + dp[prev][p]) % mod;
            }
            prev = 1 - prev, now = 1 - now;
        }
        int ans = 0;
        for(auto &num : dp[prev]) ans = (ans + num) % mod;
        return ans;
    }
};
