class Solution {
public:
    int passThePillow(int n, int time) {
        int now = 1, dir = 0;
        while(time--) {
            if(dir == 0) {
                now++;
                if(now > n) now = n - 1, dir = 1;
            } else {
                now--;
                if(now < 1) now = 2, dir = 0;
            }
        }
        return now;
    }
};
