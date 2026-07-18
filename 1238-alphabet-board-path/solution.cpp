class Solution {
public:
    pair<int, int> charToPos(char& c) {
        int idx = c - 'a';
        return {idx / 5, idx % 5};
    }
    
    string alphabetBoardPath(string target) {
        pair<int, int> now = {0, 0};
        string ans;
        for(auto& c : target) {
            auto& [x1, y1] = now;
            auto [x2, y2] = charToPos(c);
            if(x1 == 5) {
                for(int x = x1; x > x2; x--) ans += 'U';
                for(int y = y1; y < y2; y++) ans += 'R';
            } else if(x2 == 5) {
                for(int y = y1; y > y2; y--) ans += 'L';
                for(int x = x1; x < x2; x++) ans += 'D';
            } else {
                for(int x = 0; x < abs(x1 - x2); x++) ans += (x1 > x2 ? 'U' : 'D');
                for(int y = 0; y < abs(y1 - y2); y++) ans += (y1 > y2 ? 'L' : 'R');
            }
            ans += '!';
            now = {x2, y2};
        }
        return ans;
    }
};
