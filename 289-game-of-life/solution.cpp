class Solution {
public:
    bool isLive(int c) {
        return c == 1 || c == 20 || c == 21;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int cnt = 0;
                for(int k = -1; k <= 1; k++) {
                    for(int l = -1; l <= 1; l++) {
                        if(k == 0 && l == 0) continue;
                        int x = i + k, y = j + l;
                        if(x >= 0 && x < m && y >= 0 && y < n) {            
                            cnt += (isLive(board[x][y]) ? 1 : 0);
                        }
                    }
                }
                if(board[i][j] == 0) board[i][j] = cnt == 3 ? 11 : 10;
                else board[i][j] = (cnt == 2 || cnt == 3) ? 21 : 20;
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] = board[i][j] % 10;
            }
        }
    }
};
