class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int c = color == 'B' ? 'W' : 'B';
        // left side
        if(cMove >= 2 && board[rMove][cMove - 1] == c) {
            int cNow = cMove - 2;
            while(cNow >= 0) {
                if(board[rMove][cNow] == '.') break;
                if(board[rMove][cNow] == color) return true;
                cNow--;
            }
        }
        // right side
        if(cMove < 6 && board[rMove][cMove + 1] == c) {
            int cNow = cMove + 2;
            while(cNow < 8) {
                if(board[rMove][cNow] == '.') break;
                if(board[rMove][cNow] == color) return true;
                cNow++;
            }
        }
        // up side
        if(rMove >= 2 && board[rMove - 1][cMove] == c) {
            int rNow = rMove - 2;
            while(rNow >= 0) {
                if(board[rNow][cMove] == '.') break;
                if(board[rNow][cMove] == color) return true;
                rNow--;
            }
        }
        // down side
        if(rMove < 6 && board[rMove + 1][cMove] == c) {
            int rNow = rMove + 2;
            while(rNow < 8) {
                if(board[rNow][cMove] == '.') break;
                if(board[rNow][cMove] == color) return true;
                rNow++;
            }
        }
        // left up
        if(rMove >= 2 && cMove >= 2 && board[rMove - 1][cMove - 1] == c) {
            int rNow = rMove - 2, cNow = cMove - 2;
            while(rNow >= 0 && cNow >= 0) {
                if(board[rNow][cNow] == '.') break;
                if(board[rNow][cNow] == color) return true;
                rNow--; cNow--;
            }
        }
        // right down
        if(rMove < 6 && cMove < 6 && board[rMove + 1][cMove + 1] == c) {
            int rNow = rMove + 2, cNow = cMove + 2;
            while(rNow < 8 && cNow < 8) {
                if(board[rNow][cNow] == '.') break;
                if(board[rNow][cNow] == color) return true;
                rNow++; cNow++;
            }
        }
        // right up
        if(rMove >= 2 && cMove < 6 && board[rMove - 1][cMove + 1] == c) {
            int rNow = rMove - 2, cNow = cMove + 2;
            while(rNow >= 0 && cNow < 8) {
                if(board[rNow][cNow] == '.') break;
                if(board[rNow][cNow] == color) return true;
                rNow--; cNow++;
            }
        }
        // left down
        if(rMove < 6 && cMove >= 2 && board[rMove + 1][cMove - 1] == c) {
            int rNow = rMove + 2, cNow = cMove - 2;
            while(rNow < 8 && cNow >= 0) {
                if(board[rNow][cNow] == '.') break;
                if(board[rNow][cNow] == color) return true;
                rNow++; cNow--;
            }
        }
        return false;
    }
};
