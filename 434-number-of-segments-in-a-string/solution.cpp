class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        bool isSpace = true;
        for(auto x : s) {
            if(x == ' ') isSpace = true;
            else {
                if(isSpace) cnt++;
                isSpace = false;
            }
        }
        return cnt;
    }
};
