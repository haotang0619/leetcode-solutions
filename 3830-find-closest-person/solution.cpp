class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d1 = abs(x - z), d2 = abs(y - z);
        return d1 == d2 ? 0 : d1 < d2 ? 1 : 2;
    }
};
