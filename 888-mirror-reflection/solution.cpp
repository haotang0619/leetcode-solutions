class Solution {
public:
    int mirrorReflection(int p, int q) {
        int height = lcm(p, q), mirrors = height / p, times = height / q;
        if(mirrors % 2 == 0) return 0;
        return (times & 1) ? 1 : 2;
    }
};
