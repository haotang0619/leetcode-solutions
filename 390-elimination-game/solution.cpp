class Solution {
public:
    int lastRemaining(int n) {
        int size = n, ans = 1, gap = 1, round = 0;
        while(size > 1) {
            if(round % 2 == 0) ans += gap;
            else if(size % 2 == 1) ans += gap;
            round++;
            gap *= 2;
            size /= 2;
        }
        return ans;
    }
};
