class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        for(int i = 0; i <= x; i++) if((long long)i * i > (long long)x) return i - 1;
        return 0;
    }
};
