class Solution {
public:
    void solve(vector<vector<char>>& board) {
        set<vector<int>> st;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'X') continue;
                if(st.find({i, j}) != st.end()) continue;
                stack<vector<int>> sk;
                vector<vector<int>> rec;
                bool flag = true;
                sk.push({i, j});
                while(!sk.empty()) {
                    vector<int> pos = sk.top();
                    sk.pop();
                    int x = pos[0], y = pos[1];
                    if(st.find({x, y}) != st.end()) continue;
                    st.insert({x, y});
                    rec.push_back({x, y});
                    if(x - 1 < 0 || x + 1 >= m || y - 1 < 0 || y + 1 >= n) {
                        flag = false;
                    }
                    if(x - 1 >= 0 && board[x - 1][y] == 'O') sk.push({x - 1, y});
                    if(x + 1 < m && board[x + 1][y] == 'O') sk.push({x + 1, y});
                    if(y - 1 >= 0 && board[x][y - 1] == 'O') sk.push({x, y - 1});
                    if(y + 1 < n && board[x][y + 1] == 'O') sk.push({x, y + 1});
                }
                if(flag) {
                    for(auto &x : rec) board[x[0]][x[1]] = 'X';
                }
            }
        }
    }
};
