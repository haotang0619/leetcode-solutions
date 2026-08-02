class Solution {
public:
    int pivotInteger(int n) {
        for(int i = 1; i <= n; i++) {
            int sum1 = (1 + i) * i / 2, sum2 = (i + n) * (n - i + 1) / 2;
            if(sum1 == sum2) return i;
        }
        return -1;
    }
};
