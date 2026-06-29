class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        unordered_map<int, int> mp;
        for(auto& p : pairs) mp[p[0]] = p[1], mp[p[1]] = p[0];
        vector<vector<int>> pref(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - 1; j++) {
                int idx = preferences[i][j];
                pref[i][idx] = j;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int j = mp[i];
            for(auto& k : preferences[i]) {
                if(k == j) break;
                if(pref[k][mp[k]] > pref[k][i]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
