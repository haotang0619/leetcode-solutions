class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            set<char> st1;
            set<char> st2;
            for(int j = 0; j < 9; j++) {
                char c1 = board[i][j];
                char c2 = board[j][i];
                if(c1 != '.' && st1.find(c1) != st1.end()) return false;
                if(c2 != '.' && st2.find(c2) != st2.end()) return false;
                st1.insert(c1);
                st2.insert(c2);
            }
        }

        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                set<char> st;
                for(int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        int x = i + k, y = j + l;
                        char c = board[x][y];
                        if(c != '.' && st.find(c) != st.end()) return false;
                        st.insert(c);
                    }
                }
            }
        }
        
        return true;
    }
};
