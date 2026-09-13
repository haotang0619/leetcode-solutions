class Solution {
public:
    int getCnt(unordered_map<int, unordered_set<int>>& mp, int x, int y) {
        int cnt = 0;
        for(int i = x; i <= x + 1; i++) {
            for(int j = y; j <= y + 1; j++) {
                if(mp[j].contains(i)) cnt++;
            }
        }
        return cnt;
    }
    
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long> ans(5, 0);
        unordered_map<int, unordered_set<int>> mp;
        sort(coordinates.begin(), coordinates.end());
        for(auto c : coordinates) {
            mp[c[0]].insert(c[1]);
        }
        for(int y = 0; y < m - 1; y++) {
            vector<unordered_set<int>> v(5);
            for(auto& x : mp[y]) {
                if(x > 0) v[getCnt(mp, x - 1, y)].insert(x - 1);
                if(x < n - 1) v[getCnt(mp, x, y)].insert(x);
            }
            for(auto& x : mp[y + 1]) {
                if(x > 0) v[getCnt(mp, x - 1, y)].insert(x - 1);
                if(x < n - 1) v[getCnt(mp, x, y)].insert(x);
            }
            int left = n - 1;
            for(int i = 1; i < 5; i++) left -= v[i].size(), ans[i] += v[i].size();
            ans[0] += left;
        }
        return ans;
    }
};
