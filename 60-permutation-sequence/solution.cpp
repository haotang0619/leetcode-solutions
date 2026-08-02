class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<bool> vis(n + 1, false);
        vector<int> facs(n + 1, 1);
        for(int i = 2; i <= n; i++) facs[i] = i * facs[i - 1];
        while(k > 1) {
            int now = 1;
            while(vis[now]) now++;
            int cnt = facs[n - 1 - ans.size()];
            while(k - cnt >= 1) {
                k -= cnt, now++;
                while(vis[now]) now++;
            }
            ans += ('0' + now);
            vis[now] = true;
        }
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) ans += ('0' + i);
        }
        return ans;
    }
};
