class Solution {
public:
    bool judgeCircle(string moves) {
        int lcnt = 0, rcnt = 0, ucnt = 0, dcnt = 0;
        for(auto m : moves) {
            if(m == 'L') lcnt++;
            else if(m == 'R') rcnt++;
            else if(m == 'U') ucnt++;
            else dcnt++;
        }
        return lcnt == rcnt && ucnt == dcnt;
    }
};
