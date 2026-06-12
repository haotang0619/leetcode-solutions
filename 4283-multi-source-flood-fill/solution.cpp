class Solution {
public:
    int toHash(int r, int c, int m) {
        return r * m + c;
    }

    pair<int, int> toRC(int h, int m) {
        return {h / m, h % m};
    }

    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        int size = n * m;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<int, int>> qu;

        sort(sources.begin(), sources.end(), [](auto& a, auto& b) {
            return a[2] > b[2];
        });
        for(auto s : sources) {
            ans[s[0]][s[1]] = s[2];
            qu.push({s[2], toHash(s[0], s[1], m)});
        }
        
        vector<bool> visit(size, false);
        while(!qu.empty()) {
            auto [color, hash] = qu.front();
            qu.pop();
            auto [r, c] = toRC(hash, m);
            if(r - 1 >= 0 && ans[r - 1][c] == 0) {
                ans[r - 1][c] = color;
                qu.push({color, toHash(r - 1, c, m)});
            }
            if(r + 1 < n && ans[r + 1][c] == 0) {
                ans[r + 1][c] = color;
                qu.push({color, toHash(r + 1, c, m)});
            }
            if(c - 1 >= 0 && ans[r][c - 1] == 0) {
                ans[r][c - 1] = color;
                qu.push({color, toHash(r, c - 1, m)});
            }
            if(c + 1 < m && ans[r][c + 1] == 0) {
                ans[r][c + 1] = color;
                qu.push({color, toHash(r, c + 1, m)});
            }
        }
        return ans;
    }
};
