class Solution {
public:
    int maxDistance(string moves) {
        int lcnt = 0, rcnt = 0, ucnt = 0, dcnt = 0, cnt = 0;
        for(auto &c : moves) {
            if(c == 'L') lcnt++;
            else if(c == 'R') rcnt++;
            else if(c == 'U') ucnt++;
            else if(c == 'D') dcnt++;
            else cnt++;
        }
        return abs(lcnt - rcnt) + abs(ucnt - dcnt) + cnt;
    }
};
