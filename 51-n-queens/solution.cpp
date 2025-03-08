class Solution {
public:
    void findAns(vector<vector<string>>& ans, vector<string>& board, int col, int n, vector<vector<bool>>& visit) {
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(!visit[col][i]) {
                vector<vector<int>> rec;
                for(int j = col + 1; j < n; j++) {
                    if(!visit[j][i]) {
                        visit[j][i] = true;
                        rec.push_back({j, i});
                    }
                    int k = j - col;
                    if(i - k >= 0 && !visit[j][i - k]) {
                        visit[j][i - k] = true;
                        rec.push_back({j, i - k});
                    }
                    if(i + k < n && !visit[j][i + k]) { 
                        visit[j][i + k] = true;
                        rec.push_back({j, i + k});
                    }
                }
                string b(n, '.');
                b[i] = 'Q';
                board.push_back(b);
                findAns(ans, board, col + 1, n, visit);
                board.pop_back();
                for(auto x : rec) visit[x[0]][x[1]] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        findAns(ans, board, 0, n, visit);
        return ans;
    }
};
