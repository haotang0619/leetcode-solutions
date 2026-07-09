class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int, int> mp;
        int n = row.size() / 2;
        for(int i = 0; i < n; i++) {
            int a = i * 2, b = a + 1;
            mp[row[a]] = row[b];
            mp[row[b]] = row[a];
        }
        vector<bool> vis(n, false);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int a = i * 2, b = a + 1;
            int c1 = row[a] / 2, c2 = row[b] / 2;
            if(vis[c1]) continue;
            vis[c1] = true;
            int now = row[a] % 2 == 0 ? (row[a] + 1) : (row[a] - 1);
            while(c1 != c2) {
                c1 = mp[now] / 2;
                vis[c1] = true;
                ans++;
                now = mp[now] % 2 == 0 ? (mp[now] + 1) : (mp[now] - 1);
            }
        }
        return ans;
    }
};
