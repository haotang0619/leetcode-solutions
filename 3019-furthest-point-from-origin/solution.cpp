class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lcnt = 0, rcnt = 0, fcnt = 0;
        for(auto m : moves) {
            if(m == 'L') lcnt++;
            else if(m == 'R') rcnt++;
            else fcnt++;
        }
        return fcnt + abs(lcnt - rcnt);
    }
};
