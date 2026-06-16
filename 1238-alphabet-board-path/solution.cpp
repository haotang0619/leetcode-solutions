class Solution {
public:
    string alphabetBoardPath(string target) {
        unordered_map<char, pair<int, int>> mp;
        for(int i = 0; i < 26; i++) {
            char c = i + 'a';
            mp[c] = {i / 5, i % 5};
        }
        int x = 0, y = 0;
        string ans;
        for(auto c : target) {
            auto [x1, y1] = mp[c];
            if(x1 == 5) {
                for(int i = 0; i < abs(y1 - y); i++) ans += y1 > y ? 'R' : 'L';
                for(int i = 0; i < abs(x1 - x); i++) ans += x1 > x ? 'D' : 'U';
            } else {
                for(int i = 0; i < abs(x1 - x); i++) ans += x1 > x ? 'D' : 'U';
                for(int i = 0; i < abs(y1 - y); i++) ans += y1 > y ? 'R' : 'L';
            }
            x = x1, y = y1;
            ans += '!';
        }
        return ans;
    }
};
