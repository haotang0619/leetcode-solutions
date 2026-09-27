class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int x1 = source[0], y1 = source[1], x2 = target[0], y2 = target[1];
        if(x1 == x2 && y1 == y2) return 0;
        for(int i = -8; i <= 8; i++) {
            if(x1 + i == x2 && y1 + i == y2) return 1;
            if(x1 + i == x2 && y1 - i == y2) return 1;
            if(x1 - i == x2 && y1 + i == y2) return 1;
            if(x1 - i == x2 && y1 - i == y2) return 1;
        }
        if(x1 == x2) return 1;
        if(y1 == y2) return 1;
        return 2;
    }
};
