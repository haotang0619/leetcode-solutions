class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool check(vector<vector<char>>& board, vector<vector<bool>>& vis, string& word, pair<int, int> u, int idx) {
        int m = board.size(), n = board[0].size();
        if(idx == word.size()) return true;
        auto& [i, j] = u;
        for(auto& [x, y] : dir) {
            int i1 = i + x, j1 = j + y;
            if(i1 < 0 || i1 >= m || j1 < 0 || j1 >= n) continue;
            if(board[i1][j1] != word[idx]) continue;
            if(vis[i1][j1]) continue;
            vis[i1][j1] = true;
            if(check(board, vis, word, {i1, j1}, idx + 1)) return true;
            vis[i1][j1] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] != word[0]) continue;
                vis[i][j] = true;
                if(check(board, vis, word, {i, j}, 1)) return true;
                vis[i][j] = false;
            }
        }
        return false;
    }
};
