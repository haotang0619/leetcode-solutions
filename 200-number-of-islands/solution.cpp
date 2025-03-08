class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        set<vector<int>> st;
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(st.find({i, j}) != st.end()) continue;
                if(grid[i][j] == '0') continue;
                ans++;
                stack<vector<int>> sk;
                sk.push({i, j});
                while(!sk.empty()) {
                    vector<int> pos = sk.top();
                    int x = pos[0], y = pos[1];
                    sk.pop();
                    if(st.find({x, y}) != st.end()) continue;
                    st.insert({x, y});
                    if(x - 1 >= 0 && grid[x - 1][y] == '1') {
                        sk.push({x - 1, y});
                    }
                    if(x + 1 < m && grid[x + 1][y] == '1') {
                        sk.push({x + 1, y});
                    }
                    if(y - 1 >= 0 && grid[x][y - 1] == '1') {
                        sk.push({x, y - 1});
                    }
                    if(y + 1 < n && grid[x][y + 1] == '1') {
                        sk.push({x, y + 1});
                    }
                }
            }
        }
        return ans;
    }
};
