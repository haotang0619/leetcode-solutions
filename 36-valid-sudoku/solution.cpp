class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            set<char> st1, st2;
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    if(st1.contains(board[i][j])) return false;
                    st1.insert(board[i][j]);
                }
                if(board[j][i] != '.') {
                    if(st2.contains(board[j][i])) return false;
                    st2.insert(board[j][i]);
                }
            }
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                set<char> st;
                for(int k = i * 3; k < i * 3 + 3; k++) {
                    for(int l = j * 3; l < j * 3 + 3; l++) {
                        if(board[k][l] != '.') {
                            if(st.contains(board[k][l])) return false;
                            st.insert(board[k][l]);
                        }
                    }
                }
            }
        }
        return true;
    }
};
